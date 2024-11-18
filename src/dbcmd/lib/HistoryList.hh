#if !defined ODBC_CMD_LIB_HISTORY_LIST_HH
#define ODBC_CMD_LIB_HISTORY_LIST_HH

#if defined __INTELLISENSE__

// For MS IntelliSense only

# include <utility>
# include <string>
# include <list>
# include <limits>
# include <algorithm>

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

    auto capacity() const -> SIZE_TYPE;
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

#endif

#endif	    // !defined ODBC_CMD_LIB_HISTORY_LIST_HH
