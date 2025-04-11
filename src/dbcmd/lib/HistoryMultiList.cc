module;

#include "intellisense/project_headers.hh"

export module HistoryMultiList;

#if !defined MSVC_INTELLISENSE
import std;
#endif

namespace cmd
{
    using std::get;
    using std::tuple;
    using std::string;
    using std::string_view;
    using std::list;
    using std::map;

    export class HistoryMultiList
    {
    public:
	using Line = tuple<unsigned short, string const, string const>;		// ref count, timestamp, data line
	using Container = list<Line>;
	using size_type = Container::size_type;
	using const_iterator = Container::const_iterator;
	using const_reverse_iterator = Container::const_reverse_iterator;

	static auto const DEFAULT_CAPACITY = 1024u;
	static auto const NPOS = (std::numeric_limits<size_type>::max)();

	inline HistoryMultiList(size_type capacity = DEFAULT_CAPACITY, bool duplicates = false);

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

	auto remove(size_type index) -> void;

	auto append(string_view stamp, string_view lineString) -> void;
	auto append(string_view lineString) -> void;
	auto append(string &&lineString) -> void;
	auto append(string &&stamp, string &&lineString) -> void;

	auto swap(HistoryMultiList &other) -> void;
	auto swap(HistoryMultiList &&other) -> void;

    protected:
	size_type preloadedLineCount = 0u;
	size_type listCapacity = DEFAULT_CAPACITY;

	auto line(size_type index) const -> Line const &;
	auto remove(Line const &line) -> void;
	auto remove(string_view stamp, string_view lineString) -> size_type;
	auto remove(string_view lineString) -> size_type;
	auto emplaceBack(string_view stamp, string_view lineString) -> size_type;
	auto removeAndAppend(string_view stamp, string_view lineString) -> size_type;

	Container lines;
    };
}

inline cmd::HistoryMultiList::HistoryMultiList(size_type capacity, bool duplicates)
    : listCapacity { capacity }
{
}

inline auto cmd::HistoryMultiList::begin() const -> const_iterator
{
    return lines.begin();
}

inline auto cmd::HistoryMultiList::cbegin() const -> const_iterator
{
    return lines.cbegin();
}

inline auto cmd::HistoryMultiList::rbegin() const -> const_reverse_iterator
{
    return lines.rbegin();
}

inline auto cmd::HistoryMultiList::crbegin() const -> const_reverse_iterator
{
    return lines.crbegin();
}

inline auto cmd::HistoryMultiList::end() const -> const_iterator
{
    return lines.end();
}

inline auto cmd::HistoryMultiList::cend() const -> const_iterator
{
    return lines.cend();
}

inline auto cmd::HistoryMultiList::rend() const -> const_reverse_iterator
{
    return lines.rend();
}

inline auto cmd::HistoryMultiList::crend() const -> const_reverse_iterator
{
    return lines.crend();
}

inline auto cmd::HistoryMultiList::capacity() const -> size_type
{
    return listCapacity;
}

inline auto cmd::HistoryMultiList::capacity(size_type newCapacity) -> size_type
{
    using std::get;
    using std::advance;
    using std::exchange;
    using std::views::iota;

    if (newCapacity < lines.size())
    {
	size_type dropCount = lines.size() - newCapacity;
	auto it = lines.begin();

	advance(it, dropCount);

	lines.erase(lines.begin(), it);

	if (dropCount < preloadedLineCount)
	    preloadedLineCount -= dropCount;
	else
	    preloadedLineCount = 0u;
    }

    return exchange(listCapacity, newCapacity);
}

inline auto cmd::HistoryMultiList::line(size_type index) const -> Line const &
{
    auto it = lines.cbegin();

    return std::ranges::advance(it, index), *it;
}

inline auto cmd::HistoryMultiList::remove(size_type index) -> void
{
    using std::get;
    using std::ranges::advance;

    if (auto it = lines.begin(); lines.size() > index)
	lines.erase((advance(it, index), it));
}

inline auto cmd::HistoryMultiList::remove(Line const &line) -> void
{
    using std::get;
    using std::views::iota;
    using std::find_if;

    auto it = find_if(lines.begin(), lines.end(), [&line](auto ln)
	{
	    return ln == line;
	});

    if (it != lines.end())
	lines.erase(it);
}

inline auto cmd::HistoryMultiList::remove(std::string_view stamp, std::string_view lineString) -> size_type
{
    for (auto [index, it]: std::views::iota(lines.begin(), lines.end()) | std::views::enumerate)
	if (get<1>(*it)== stamp && get<2>(*it) == lineString)
	    return lines.erase(it), index;

    return NPOS;
}

inline auto cmd::HistoryMultiList::remove(std::string_view lineString) -> size_type
{
    auto found_index = NPOS, index = size_type { };

    for (auto it = lines.begin(); it != lines.end(); index++)
	it = get<2>(*it) == lineString
	? found_index = (std::min)(found_index, index), lines.erase(it)
	: ++it;

    return found_index;
}

inline auto cmd::HistoryMultiList::emplaceBack(string_view stamp, string_view lineString) -> size_type
{
    lines.emplace_back(0, stamp, lineString);

    if (lines.size() > listCapacity)
	return lines.pop_front(), 0u;

    return lines.size() - 1u;
}

inline auto cmd::HistoryMultiList::removeAndAppend(string_view stamp, string_view lineString) -> size_type
{
    auto index = remove(lineString);

    return (std::min)(index, emplaceBack(stamp, lineString));
}

inline auto cmd::HistoryMultiList::swap(HistoryMultiList &other) -> void
{
    lines.swap(other.lines);
    std::swap(listCapacity, other.listCapacity);
    std::swap(preloadedLineCount, other.preloadedLineCount);
}

inline auto cmd::HistoryMultiList::swap(HistoryMultiList &&other) -> void
{
    swap(other);
}
