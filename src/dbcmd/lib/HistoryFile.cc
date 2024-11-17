#if defined WINDOWS
# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif
# if defined(_M_IX86) && !defined(_X68_)
#  define _X86_
# endif
#endif

#if defined WINDOWS
# include <ShlObj.h>
#endif

#include <cstdlib>

#include <memory>
#include <iterator>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <ranges>

#include "HistoryFile.hh"

using std::unique_ptr;
using std::distance;
using std::string;
using std::string_view;
using std::filesystem::path;
using std::filesystem::create_directories;

#if defined WINDOWS

static auto HistoryList_AppConfigPath(string_view appName = "ODBC-Cmd") -> path
{
    static auto appConfigPath = path { };

    if (appConfigPath.empty())
    {
	auto configPath = PWSTR { };
	auto dwResult = ::SHGetKnownFolderPath(FOLDERID_RoamingAppData, KF_FLAG_DEFAULT, NULL, &configPath);

	if (dwResult == S_OK)
	{
	    appConfigPath = path { configPath };

	    CoTaskMemFree(configPath);
	}
	else
	{
	    char const *appDataPath = getenv("APPDATA");;

	    if (appDataPath)
		appConfigPath = path { appDataPath };
	    else
		appConfigPath = ".";
	}
    }

    auto configPath = appConfigPath / appName;

    create_directories(configPath);

    return configPath;
}

#else
# error Not implemented, use getent() and getenv("HOME")/.config/$appName
#endif

static auto HistoryList_MakeAppConfigPath(path const &file_path) -> path
{
    return distance(file_path.begin(), file_path.end()) > 1 && !file_path.begin()->empty()
	? file_path
	: HistoryList_AppConfigPath() / file_path;
}

cmd::HistoryList::HistoryList(path const &file_path):
    historyFile(localFile)
{
    file_stream_buffer.open(HistoryList_MakeAppConfigPath(file_path).string());
    historyFile.exceptions(historyFile.exceptions() | historyFile.badbit);
    reload();
}

auto cmd::HistoryList::clear() -> void
{
    lines.clear();
    lineIndex.clear();
    cleanEntriesCount = OUT_OF_RANGE_COUNT;
    historyFile.clear();
    historyFile.seekg(0, historyFile.beg);
    historyFile.seekp(0, historyFile.beg);
}

auto cmd::HistoryList::reload() -> void
{
    clear();

    auto line = std::string { };

    using std::views::all;

    while (std::getline(historyFile, line).good() && (line.empty() || line[0] != '\x1A'))
	if (line | all)
	{
	    lines.push_back(line);
	    lineIndex.emplace_back(pos_type { historyFile.tellg() }, lines.crend().base());
	}
}

auto cmd::HistoryList::defaultTruncate(std::streambuf *stream_buf) -> void
{
    stream_buf->sputc('\x1A');				// ASCII End-Of-File (char code 26, Ctrl+Z)
    stream_buf->pubsync();
    stream_buf->sputn("", std::streamsize { 0 });	// try to truncate the file
}

auto cmd::HistoryList::save() -> void
{
    using std::ranges::views::drop;

    if (isDirty())
    {
	historyFile.seekp(cleanEntriesCount ? lineIndex[cleanEntriesCount - 1u].first : std::streampos { 0 });

	for (auto &index : lineIndex | drop(cleanEntriesCount))
	{
	    historyFile << *index.second << '\n';
	    index.first = pos_type { historyFile.tellp() };
	}

	cleanEntriesCount = OUT_OF_RANGE_COUNT;
	historyFile << std::flush;

	truncate_func(historyFile.rdbuf());
    }
}

auto cmd::HistoryList::appendLine(std::string_view line) -> void
{
    for (auto const &&[index, historyLine]: lines | std::views::enumerate)
	if (historyLine == line)
	    return appendLine(index + 1u);

    if (cleanEntriesCount > size())
	cleanEntriesCount = size();

    lines.emplace_back(line);
    lineIndex.emplace_back
    (
	lineIndex.empty() ? 0 : std::streamsize { lineIndex.back().first } + lines.back().length() + 1u,
	lines.crend().base()
    );
}

auto cmd::HistoryList::appendLine(unsigned lineNumber) -> void
{
    lines.splice(lines.end(), lines, lineIndex[lineNumber - 1u].second);

    if (cleanEntriesCount > lineNumber - 1u)
	cleanEntriesCount = lineNumber - 1u;

    lineIndex.erase(lineIndex.cbegin() + lineNumber - 1u);
}

auto cmd::HistoryList::removeLine(unsigned lineNumber) -> void
{
    if (cleanEntriesCount > lineNumber - 1u)
	cleanEntriesCount = lineNumber - 1u;

    lines.erase(lineIndex[lineNumber - 1u].second);
    lineIndex.erase(lineIndex.cbegin() + lineNumber - 1u);
}
