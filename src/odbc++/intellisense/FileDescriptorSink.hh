#if !defined(SQL_ODBCXX_FILE_DESCRIPTOR_SINK)
#define SQL_ODBCXX_FILE_DESCRIPTOR_SINK

#if defined MSVC_INTELLISENSE

// For MS IntelliSense only

namespace odbc
{
    class FileDescriptorSink: public FileDescriptorDevice
    {
    public:
	struct category: boost::iostreams::closable_tag, boost::iostreams::output_seekable, boost::iostreams::device_tag
	{
	};

	FileDescriptorSink() = default;
	FileDescriptorSink(HandleType handle, Flags flags);
	FileDescriptorSink(std::filesystem::path const &path, std::ios_base::openmode mode = std::ios_base::out);
	FileDescriptorSink(std::string const &path, std::ios_base::openmode mode = std::ios_base::out);
	FileDescriptorSink(char const *path, std::ios_base::openmode mode = std::ios_base::out);
	FileDescriptorSink(wchar_t const *path, std::ios_base::openmode mode = std::ios_base::out);

	void open(std::filesystem::path const &path, std::ios_base::openmode mode = std::ios_base::out, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)());
	void open(std::string const &path, std::ios_base::openmode mode = std::ios_base::out, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)());
	void open(char const *path, std::ios_base::openmode mode = std::ios_base::out, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)());
	void open(wchar_t const *path, std::ios_base::openmode mode = std::ios_base::out, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)());

	using FileDescriptorDevice::write;
	using FileDescriptorDevice::seek;
    };
}

#endif	    // defined MSVC_INTELLISENSE

#endif	    // !defined(SQL_ODBCXX_FILE_DESCRIPTOR_SINK)
