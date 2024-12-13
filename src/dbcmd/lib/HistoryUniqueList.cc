module;

#include "intellisense/project_headers.hh"

export module HistoryUniqueList;

#if !defined MSVC_INTELLISENSE
import std;
import local.boost.intrusive;
#endif

namespace cmd
{
    using std::move;
    using std::get;
    using std::tuple;
    using std::string;
    using std::string_view;
    using std::map;

#if defined MSVC_INTELLISENSE
    namespace ext
    {
	namespace boost = ::boost;
    }
#endif

    using ext::boost::intrusive::link_mode;
    using ext::boost::intrusive::normal_link;
    using ext::boost::intrusive::list_base_hook;
    using ext::boost::intrusive::list;
    using ext::boost::intrusive::set_base_hook;
    using ext::boost::intrusive::set;

    using ext::boost::intrusive::detail::destructor_impl;

    export class HistoryUniqueList
    {
    public:
	struct Line:
	    public list_base_hook<link_mode<normal_link>>,
	    public set_base_hook<link_mode<normal_link>>,
	    public tuple<unsigned short, string const, string const>		// ref count, timestamp, data line
	{
	    Line(unsigned short count, string_view stamp, string_view line);
	    Line(unsigned short count, string &&stamp, string &&line);
	    Line(Line &&line);
	};

	using Container = list<Line>;
	using size_type = Container::size_type;
	using const_iterator = Container::const_iterator;
	using const_reverse_iterator = Container::const_reverse_iterator;

	static auto const DEFAULT_CAPACITY = 1024u;
	static auto const NPOS = (std::numeric_limits<size_type>::max)();

	inline HistoryUniqueList(size_type capacity = DEFAULT_CAPACITY, bool duplicates = false);

	auto begin()	const -> const_iterator;
	auto end()	const -> const_iterator;
	auto cbegin()	const -> const_iterator;
	auto cend()	const -> const_iterator;
	auto rbegin()	const -> const_reverse_iterator;
	auto rend()	const -> const_reverse_iterator;
	auto crbegin()	const -> const_reverse_iterator;
	auto crend()	const -> const_reverse_iterator;

	auto capacity() const -> size_type;
	auto capacity(size_type newCapacity) -> size_type;

	auto duplicates() const -> bool;
	auto duplicates(bool dup) -> bool;

	auto remove(size_type index) -> void;

	auto append(string_view stamp, string_view lineString) -> void;
	auto append(string_view lineString) -> void;
	auto append(string &&lineString) -> void;
	auto append(string &&stamp, string &&lineString) -> void;

	auto swap(HistoryUniqueList &other) -> void;
	auto swap(HistoryUniqueList &&other) -> void;

    protected:
	using Index = map<string, const_iterator>;

	bool keepDuplicates = false;
	size_type preloadedLineCount = 0u;
	size_type listCapacity = DEFAULT_CAPACITY;

	auto buildIndex() -> void;
	auto line(size_type index) const -> Line const &;
	auto remove(Line const &line) -> void;
	auto remove(string_view stamp, string_view lineString) -> size_type;
	auto remove(string_view lineString) -> size_type;
	auto emplaceBack(string_view stamp, string_view lineString) -> void;
	auto removeAndAppend(string_view stamp, string_view lineString) -> void;

	Container lines;
	Index index;
    };
}

inline cmd::HistoryUniqueList::Line::Line(unsigned short count, string_view stamp, string_view line)
    : tuple { count, stamp, line }
{
}

inline cmd::HistoryUniqueList::Line::Line(unsigned short count, string &&stamp, string &&line)
    : tuple { count, move(stamp), move(line) }
{
}

inline cmd::HistoryUniqueList::Line::Line(Line &&line)
    : tuple { get<0>(line), move(get<1>(line)), move(get<2>(line)) }
{
}

inline cmd::HistoryUniqueList::HistoryUniqueList(size_type capacity, bool duplicates)
    : listCapacity { capacity }, keepDuplicates { duplicates }
{
}

inline auto cmd::HistoryUniqueList::begin() const -> const_iterator
{
    return lines.begin();
}

inline auto cmd::HistoryUniqueList::cbegin() const -> const_iterator
{
    return lines.cbegin();
}

inline auto cmd::HistoryUniqueList::rbegin() const -> const_reverse_iterator
{
    return lines.rbegin();
}

inline auto cmd::HistoryUniqueList::crbegin() const -> const_reverse_iterator
{
    return lines.crbegin();
}

inline auto cmd::HistoryUniqueList::end() const -> const_iterator
{
    return lines.end();
}

inline auto cmd::HistoryUniqueList::cend() const -> const_iterator
{
    return lines.cend();
}

inline auto cmd::HistoryUniqueList::rend() const -> const_reverse_iterator
{
    return lines.rend();
}

inline auto cmd::HistoryUniqueList::crend() const -> const_reverse_iterator
{
    return lines.crend();
}

inline auto cmd::HistoryUniqueList::capacity() const -> size_type
{
    return listCapacity;
}

inline auto cmd::HistoryUniqueList::capacity(size_type newCapacity) -> size_type
{
    using std::get;
    using std::advance;
    using std::exchange;
    using std::views::iota;

    if (newCapacity < lines.size())
    {
	size_type dropCount = lines.size() - newCapacity;
	auto it = lines.begin();

	for (auto const &i: iota(size_type { 0 }, dropCount))
	    index.erase(get<2>(*it++));

	lines.erase(lines.begin(), it);

	if (dropCount < preloadedLineCount)
	    preloadedLineCount -= dropCount;
	else
	    preloadedLineCount = 0u;
    }

    return exchange(listCapacity, newCapacity);
}

inline auto cmd::HistoryUniqueList::duplicates() const -> bool
{
    return keepDuplicates;
}

inline auto cmd::HistoryUniqueList::buildIndex() -> void
{
    using std::get;
    using std::exchange;
    using std::views::iota;
    using std::views::enumerate;

    for (auto const [idx, it]: iota(lines.begin(), lines.end()) | enumerate)
    {
	auto [jt, inserted] = index.emplace(get<2>(*it), it);

	if (!inserted)
	{
	    lines.erase(exchange(get<1>(*jt), it));	// de-duplicate existing lines, with last
							// line being kept in favor of previous
							// ones with the same string value

	    if (idx < preloadedLineCount)
		preloadedLineCount--;
	}
    }
}

inline auto cmd::HistoryUniqueList::duplicates(bool dup) -> bool
{
    using std::exchange;

    if (dup)
	if (keepDuplicates)
	    ;
	else
	    buildIndex();
    else
	index.clear();

    return exchange(keepDuplicates, dup);
}

inline auto cmd::HistoryUniqueList::line(size_type index) const -> Line const &
{
    auto it = lines.cbegin();

    return std::ranges::advance(it, index), *it;
}

inline auto cmd::HistoryUniqueList::remove(size_type index) -> void
{
    using std::get;
    using std::ranges::advance;

    if (auto it = lines.begin(); lines.size() > index)
	delete &*lines.erase((advance(it, index), this->index.erase(get<2>(*it)), it));
}

inline auto cmd::HistoryUniqueList::remove(Line const &line) -> void
{
    using std::get;
    using std::views::iota;
    using std::find_if;

    auto it = find_if(lines.begin(), lines.end(), [&line](auto const &ln)
	{
	    return ln == line;
	});

    if (it != lines.cend())
    {
	index.erase(get<2>(*it));
	delete &*lines.erase(it);
    }
}

inline auto cmd::HistoryUniqueList::remove(std::string_view stamp, std::string_view lineString) -> size_type
{
    for (auto [index, it]: std::views::iota(lines.begin(), lines.end()) | std::views::enumerate)
	if (get<1>(*it) == stamp && get<2>(*it) == lineString)
	{
	    this->index.erase(get<2>(*it));
	    return delete &*lines.erase(it), index;
	}

    return NPOS;
}

inline auto cmd::HistoryUniqueList::remove(std::string_view lineString) -> size_type
{
    auto found_index = NPOS, index = size_type { };

    for (auto it = lines.begin(); it != lines.end(); index++)
	it = get<2>(*it) == lineString
	? found_index = (std::min)(found_index, index), lines.erase(it)
	: ++it;

    return found_index;
}

inline auto cmd::HistoryUniqueList::emplaceBack(string_view stamp, string_view lineString) -> void
{
    lines.push_back(* new Line { 1, stamp, lineString });

    if (lines.size() > listCapacity)
    {
	lines.pop_front();

	if (preloadedLineCount)
	    preloadedLineCount--;
    }
}

inline auto cmd::HistoryUniqueList::removeAndAppend(string_view stamp, string_view lineString) -> void
{
    remove(lineString);
    emplaceBack(stamp, lineString);
}

inline auto cmd::HistoryUniqueList::swap(HistoryUniqueList &other) -> void
{
    lines.swap(other.lines);
    index.swap(other.index);
    std::swap(listCapacity, other.listCapacity);
    std::swap(keepDuplicates, other.keepDuplicates);
    std::swap(preloadedLineCount, other.preloadedLineCount);
}

inline auto cmd::HistoryUniqueList::swap(HistoryUniqueList &&other) -> void
{
    swap(other);
}
