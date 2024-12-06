#if !defined(SQL_ODBCXX_FILE_DESCRIPTOR_DEVICE)
#define SQL_ODBCXX_FILE_DESCRIPTOR_DEVICE

#if defined MSVC_INTELLISENSE

// For MS IntelliSense only

namespace odbc
{
    class FileDescriptorDevice
    {
    public:
#if defined WINDOWS
	using HandleType = HANDLE;
#else
	using HandleType = int;
#endif

	using char_type = char;
	using handle_type = HandleType;

	enum class Flags
	{
	    None,
	    CloseOnRelease,
	    AppendMode
	};

	friend std::underlying_type_t<Flags> operator +(Flags flags)
	{
	    return static_cast<std::underlying_type_t<Flags>>(flags);
	}

	FileDescriptorDevice() = default;

	FileDescriptorDevice(HandleType handle, Flags flags);
	~FileDescriptorDevice();

	void open(HandleType handle, Flags flags);
	bool isOpen() const;
	HandleType handle() const;
	void close();

    protected:
	static constexpr auto const MAX_DWORD = (std::numeric_limits<DWORD>::max)();

	FileDescriptorDevice(std::filesystem::path const &path, std::ios_base::openmode mode);
	FileDescriptorDevice(std::string const &path, std::ios_base::openmode mode);
	FileDescriptorDevice(char const *path, std::ios_base::openmode mode);
	FileDescriptorDevice(wchar_t const *path, std::ios_base::openmode mode);
	void open(std::filesystem::path const &path, std::ios_base::openmode mode, DWORD dwShareMode = MAX_DWORD);
	void open(std::string const &path, std::ios_base::openmode mode, DWORD dwShareMode = MAX_DWORD);
	void open(char const *path, std::ios_base::openmode mode, DWORD dwShareMode = MAX_DWORD);
	void open(wchar_t const *path, std::ios_base::openmode mode, DWORD dwShareMode = MAX_DWORD);
	std::streamsize read(char *buffer, std::streamsize bufferSize);
	std::streamsize write(const char *buffer, std::streamsize bufferSize);
	std::streampos seek(boost::iostreams::stream_offset off, std::ios_base::seekdir way);

	Flags flags { Flags::None };

#if defined WINDOWS
	HandleType fileHandle = INVALID_HANDLE_VALUE;
#else
	HandleType fileHhandle = -1;
#endif
    };
}

#endif	    // defined MSVC_INTELLISENSE

#endif	    // !defined(SQL_ODBCXX_FILE_DESCRIPTOR_DEVICE)
