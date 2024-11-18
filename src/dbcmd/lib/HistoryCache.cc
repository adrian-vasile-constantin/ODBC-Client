module;

// #include <vector>
// #include <list>
// #include <string>
// #include <filesystem>

// #include "HistoryList.hh"
// #include "HistoryFile.hh"

#if defined __INTELLISENSE__
# include <vector>
# include <tuple>
# include <string>
# include <filesystem>

# include "HistoryList.hh"
#endif

export module HistoryCache;

#if !defined __INTELLISENSE__
import std;
import HistoryList;
#endif

namespace cmd
{
    export class HistoryCache
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

module :private;

using std::tuple;
using std::vector;
using std::string;
using std::filesystem::path;

namespace cmd
{
    HistoryCache::HistoryCache(path const &filePath)
    {
    }

    HistoryCache::HistoryCache(Type const historyType)
    {
    }

    auto HistoryCache::flush() -> void
    {
    }

    auto HistoryCache::history() -> HistoryList const &
    {
	return historyList;
    }
}
