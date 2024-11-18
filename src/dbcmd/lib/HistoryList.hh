#if !defined ODBC_CMD_LIB_HISTORY_LIST_HH
#define ODBC_CMD_LIB_HISTORY_LIST_HH

#include <limits>
#include <utility>
#include <iterator>
#include <list>
#include <string>
#include <ranges>
#include <algorithm>

namespace cmd
{
    class HistoryList
    {
    public:
	using Line = std::pair<std::string, std::string>;
	using Container = std::list<Line>;
	using SIZE_TYPE = Container::size_type;
	using const_iterator = Container::const_iterator;
	using const_reverse_iterator = Container::const_reverse_iterator;

    protected:
	Container lines;
	SIZE_TYPE listCapacity;

	auto remove(Line const &line) -> SIZE_TYPE;

    public:
	static auto const DEFAULT_CAPACITY = 1024u;
	static auto const NPOS = (std::numeric_limits<SIZE_TYPE>::max)();

	HistoryList(SIZE_TYPE capacity = DEFAULT_CAPACITY);

	auto begin() const -> const_iterator;
	auto cbegin() const -> const_iterator;
	auto rbegin() const -> const_reverse_iterator;
	auto crbegin() const -> const_reverse_iterator;

	auto end() const -> const_iterator;
	auto cend() const -> const_iterator;
	auto rend() const -> const_reverse_iterator;
	auto crend() const -> const_reverse_iterator;
	
	auto capacity() const ->SIZE_TYPE;
	auto capacity(SIZE_TYPE newCapacity) -> SIZE_TYPE;

	auto line(SIZE_TYPE index) const -> Line const &;

	auto remove(SIZE_TYPE index) -> SIZE_TYPE;
	auto remove(std::string_view stamp, std::string_view lineString) -> SIZE_TYPE;
	auto remove(std::string_view lineString) -> SIZE_TYPE;

	auto emplaceBack(std::string_view stamp, std::string_view lineString) -> SIZE_TYPE;
	auto removeAndAppend(std::string_view stamp, std::string_view lineString) -> SIZE_TYPE;

	auto swap(HistoryList &other) -> void;
	auto swap(HistoryList &&other) -> void;
    };
}

inline cmd::HistoryList::HistoryList(SIZE_TYPE capacity)
    : listCapacity { capacity }
{
}

inline auto cmd::HistoryList::begin() const -> const_iterator
{
    return lines.begin();
}

inline auto cmd::HistoryList::cbegin() const -> const_iterator
{
    return lines.cbegin();
}

inline auto cmd::HistoryList::rbegin() const -> const_reverse_iterator
{
    return lines.rbegin();
}

inline auto cmd::HistoryList::crbegin() const -> const_reverse_iterator
{
    return lines.crbegin();
}

inline auto cmd::HistoryList::end() const -> const_iterator
{
    return lines.end();
}

inline auto cmd::HistoryList::cend() const -> const_iterator
{
    return lines.cend();
}

inline auto cmd::HistoryList::rend() const -> const_reverse_iterator
{
    return lines.rend();
}

inline auto cmd::HistoryList::crend() const -> const_reverse_iterator
{
    return lines.crend();
}

inline auto cmd::HistoryList::capacity() const -> SIZE_TYPE
{
    return listCapacity;
}

inline auto cmd::HistoryList::capacity(SIZE_TYPE newCapacity) -> SIZE_TYPE
{
    return std::exchange(listCapacity, newCapacity);
}

inline auto cmd::HistoryList::line(SIZE_TYPE index) const -> Line const &
{
    auto it = lines.cbegin();

    return std::ranges::advance(it, index), *it;
}

inline auto cmd::HistoryList::remove(SIZE_TYPE index) -> SIZE_TYPE
{
    if (auto it = lines.begin(); lines.size() > index)
	return lines.erase((std::ranges::advance(it, index), it)), index;

    return NPOS;
}

inline auto cmd::HistoryList::remove(Line const &line) -> SIZE_TYPE
{
    namespace views = std::views;
    namespace ranges = std::ranges;
    using std::get;

    auto it = ranges::find_if(views::iota(lines.begin(), lines.end()) | views::enumerate, [&line](auto enumerated)
	{
	    return *get<1>(enumerated) == line;
	});

    return get<1>(*it) == lines.end() ? NPOS : (lines.erase(get<1>(*it)), get<0>(*it));
}

inline auto cmd::HistoryList::remove(std::string_view stamp, std::string_view lineString) -> SIZE_TYPE
{
    for (auto [index, it]: std::ranges::iota_view(lines.begin(), lines.end()) | std::views::enumerate)
	if (it->first == stamp && it->second == lineString)
	    return lines.erase(it), index;

    return NPOS;
}

inline auto cmd::HistoryList::remove(std::string_view lineString) -> SIZE_TYPE
{
    auto found_index = NPOS, index = SIZE_TYPE { };

    for (auto it = lines.begin(); it != lines.end(); index++)
	it = it->second == lineString
	    ? found_index = (std::min)(found_index, index), lines.erase(it)
	    : ++it;

    return found_index;
}

inline auto cmd::HistoryList::emplaceBack(std::string_view stamp, std::string_view lineString) -> SIZE_TYPE
{
    lines.emplace_back(stamp, lineString);

    if (lines.size() > listCapacity)
	return lines.pop_front(), 0u;
    
    return lines.size() - 1u;
}

inline auto cmd::HistoryList::removeAndAppend(std::string_view stamp, std::string_view lineString) -> SIZE_TYPE
{
    auto index = remove(lineString);

    return (std::min)(index, emplaceBack(stamp, lineString));
}

inline auto cmd::HistoryList::swap(HistoryList &other) -> void
{
    lines.swap(other.lines);
    std::swap(listCapacity, other.listCapacity);
}

inline auto cmd::HistoryList::swap(HistoryList &&other) -> void
{
    swap(other);
}

#endif	    // !defined ODBC_CMD_LIB_HISTORY_LIST_HH
