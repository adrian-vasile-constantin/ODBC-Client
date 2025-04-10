#if !defined ODBC_CMD_LIB_HISTORY_UNIQUE_LIST_HH
#define ODBC_CMD_LIB_HISTORY_UNIQUE_LIST_HH

#if defined MSVC_INTELLISENSE

// For MS IntelliSense only

#include "intellisense/project_headers.hh"

namespace cmd
{
    using std::move;
    using std::get;
    using std::tuple;
    using std::string;
    using std::string_view;
    using std::map;

    using ext::boost::intrusive::link_mode;
    using ext::boost::intrusive::normal_link;
    using ext::boost::intrusive::list_base_hook;
    using ext::boost::intrusive::list;
    using ext::boost::intrusive::set_base_hook;
    using ext::boost::intrusive::set;

    export class HistoryUniqueList
    {
    public:
	enum class Operation
	{
	    LineLiteral,
	    IndexedDelete,
	    DeleteLineString,
	    AppendLineString
	};

	struct Line:
	    public list_base_hook<link_mode<normal_link>>,
	    public set_base_hook<link_mode<normal_link>>,
	    public tuple<Operation, string const, string const>		// ref count, timestamp, data line
	{
	    Line(Operation op, string_view stamp, string_view line);
	    Line(Operation op, string &&stamp, string &&line);
	    Line(Line &&line);
	};

	using Container = list<Line>;
	using size_type = Container::size_type;
	using const_iterator = Container::const_iterator;
	using const_reverse_iterator = Container::const_reverse_iterator;

	static auto const DEFAULT_CAPACITY = 1024u;
	static auto const NPOS = (std::numeric_limits<size_type>::max)();

	inline HistoryUniqueList(size_type capacity = DEFAULT_CAPACITY, bool duplicates = false);

	auto begin()	const->const_iterator;
	auto end()	const->const_iterator;
	auto cbegin()	const->const_iterator;
	auto cend()	const->const_iterator;
	auto rbegin()	const->const_reverse_iterator;
	auto rend()	const->const_reverse_iterator;
	auto crbegin()	const->const_reverse_iterator;
	auto crend()	const->const_reverse_iterator;

	auto capacity() const->size_type;
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
	auto line(size_type index) const->Line const &;
	auto remove(Line const &line) -> void;
	auto remove(string_view stamp, string_view lineString) -> void;
	auto remove(string_view lineString) -> size_type;
	auto emplaceBack(string_view stamp, string_view lineString) -> void;
	auto removeAndAppend(string_view stamp, string_view lineString) -> void;

	Container lines;
	Index index;
    };
}

#endif

#endif	    // !defined ODBC_CMD_LIB_HISTORY_UNIQUE_LIST_HH
