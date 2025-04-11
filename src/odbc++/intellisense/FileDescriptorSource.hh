#if !defined(SQL_ODBCXX_FILE_DESCRIPTOR_SOURCE)
#define SQL_ODBCXX_FILE_DESCRIPTOR_SOURCE

#if defined MSVC_INTELLISENSE

// For MS IntelliSense only

namespace odbc
{
    class FileDescriptorSource: public FileDescriptorDevice
    {
    public:
	struct category: boost::iostreams::closable_tag, boost::iostreams::input_seekable, boost::iostreams::device_tag
	{
	};

	FileDescriptorSource() = default;
	FileDescriptorSource(HandleType handle, Flags flags);
	FileDescriptorSource(std::filesystem::path const &path, std::ios_base::openmode mode = std::ios_base::in);
	FileDescriptorSource(std::string const &path, std::ios_base::openmode mode = std::ios_base::in);
	FileDescriptorSource(char const *path, std::ios_base::openmode mode = std::ios_base::in);
	FileDescriptorSource(wchar_t const *path, std::ios_base::openmode mode = std::ios_base::in);

	void open(std::filesystem::path const &path, std::ios_base::openmode mode = std::ios_base::in, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)());
	void open(std::string const &path, std::ios_base::openmode mode = std::ios_base::in, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)());
	void open(char const *path, std::ios_base::openmode mode = std::ios_base::in, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)());
	void open(wchar_t const *path, std::ios_base::openmode mode = std::ios_base::in, DWORD dwShareMode = (std::numeric_limits<DWORD>::max)());

	using FileDescriptorDevice::read;
	using FileDescriptorDevice::seek;
    };
}

#endif	    // defined MSVC_INTELLISENSE

#endif	    // !defined(SQL_ODBCXX_FILE_DESCRIPTOR_SOURCE)
