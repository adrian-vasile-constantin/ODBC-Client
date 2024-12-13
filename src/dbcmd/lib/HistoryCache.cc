module;

#include "intellisense/project_headers.hh"

export module HistoryCache;

#if !defined MSVC_INTELLISENSE
import std;
import HistoryUniqueList;
import HistoryMultiList;
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
	HistoryUniqueList historyList;

    public:
	enum class Type
	{
	    ConnectionHistory,
	    CommandHistory
	};

	HistoryCache(std::filesystem::path const &filePath);
	HistoryCache(Type const historyType);

	auto flush() -> void;
	auto history() -> HistoryUniqueList const &;
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

    auto HistoryCache::history() -> HistoryUniqueList const &
    {
	return historyList;
    }
}
