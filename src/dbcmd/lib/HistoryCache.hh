#if !defined ODBC_CMD_LIB_HISTORY_CACHE_HH
#define ODBC_CMD_LIB_HISTORY_CACHE_HH

#include <vector>
#include <list>
#include <string>
#include <filesystem>

#include "HistoryList.hh"
#include "HistoryFile.hh"

namespace cmd
{
    class HistoryCache
    {
    protected:
	enum class Operation
	{
	    DeleteEntry,
	    DeleteLineString,
	    DeleateAndAppendLineString
	};

	using Journal = std::vector<std::tuple<Operation, std::string, std::string>>;
	
	Journal journal;
	HistoryList historyList;

    public:
	enum class Type
	{
	    ConnectionHistory,
	    CommandHistory
	};

	HistoryCache(std::filesystem::path const &filePath);
	HistoryCache(Type const historyType);

	auto flush() -> void;
	auto history() -> HistoryList const &;
    };
}

#endif	    // !defined ODBC_CMD_LIB_HISTORY_CACHE_HH
