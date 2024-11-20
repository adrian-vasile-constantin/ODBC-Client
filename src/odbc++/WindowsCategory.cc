module;

#if defined(_WINDOWS)
# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif
# if defined(_M_IX86) && !defined(_X68_)
#  define _X86_
# endif
#endif

#if defined WINDOWS
# include <windef.h>
# include <winerror.h>
# include <WinBase.h>
# include <errhandlingapi.h>
#endif

#include "intellisense/odbcxx_project_headers.hh"

#include "ODBCXX_export.h"

export module odbc.WindowsCategory;

#if !defined MSVC_INTELLISENSE
import std;
#endif

namespace odbc
{
    export enum class WindowsError: DWORD
    {
	ACCESS_DENIED = ERROR_ACCESS_DENIED,
	ACCOUNT_DISABLED = ERROR_ACCOUNT_DISABLED,
	ACCOUNT_RESTRICTION = ERROR_ACCOUNT_RESTRICTION,
	ACTIVE_CONNECTIONS = ERROR_ACTIVE_CONNECTIONS,
	ADAP_HDW_ERR = ERROR_ADAP_HDW_ERR,
	ALREADY_ASSIGNED = ERROR_ALREADY_ASSIGNED,
	ALREADY_EXISTS = ERROR_ALREADY_EXISTS,
	ARENA_TRASHED = ERROR_ARENA_TRASHED,
	ARITHMETIC_OVERFLOW = ERROR_ARITHMETIC_OVERFLOW,
	BAD_COMMAND = ERROR_BAD_COMMAND,
	BAD_DEVICE = ERROR_BAD_DEVICE,
	BAD_DEV_TYPE = ERROR_BAD_DEV_TYPE,
	BAD_DRIVER_LEVEL = ERROR_BAD_DRIVER_LEVEL,
	BAD_ENVIRONMENT = ERROR_BAD_ENVIRONMENT,
	BAD_EXE_FORMAT = ERROR_BAD_EXE_FORMAT,
	BAD_FORMAT = ERROR_BAD_FORMAT,
	BAD_LENGTH = ERROR_BAD_LENGTH,
	BAD_NETPATH = ERROR_BAD_NETPATH,
	BAD_NET_NAME = ERROR_BAD_NET_NAME,
	BAD_NET_RESP = ERROR_BAD_NET_RESP,
	BAD_PATHNAME = ERROR_BAD_PATHNAME,
	BAD_PIPE = ERROR_BAD_PIPE,
	BAD_REM_ADAP = ERROR_BAD_REM_ADAP,
	BAD_UNIT = ERROR_BAD_UNIT,
	BAD_USERNAME = ERROR_BAD_USERNAME,
	BEGINNING_OF_MEDIA = ERROR_BEGINNING_OF_MEDIA,
	BROKEN_PIPE = ERROR_BROKEN_PIPE,
	BUFFER_OVERFLOW = ERROR_BUFFER_OVERFLOW,
	BUSY = ERROR_BUSY,
	BUSY_DRIVE = ERROR_BUSY_DRIVE,
	BUS_RESET = ERROR_BUS_RESET,
	CALL_NOT_IMPLEMENTED = ERROR_CALL_NOT_IMPLEMENTED,
	CANCELLED = ERROR_CANCELLED,
	CANNOT_MAKE = ERROR_CANNOT_MAKE,
	CANTOPEN = ERROR_CANTOPEN,
	CANTREAD = ERROR_CANTREAD,
	CANTWRITE = ERROR_CANTWRITE,
	CHILD_NOT_COMPLETE = ERROR_CHILD_NOT_COMPLETE,
	COMMITMENT_LIMIT = ERROR_COMMITMENT_LIMIT,
	CONNECTION_REFUSED = ERROR_CONNECTION_REFUSED,
	CRC = ERROR_CRC,
	CURRENT_DIRECTORY = ERROR_CURRENT_DIRECTORY,
	DEVICE_DOOR_OPEN = ERROR_DEVICE_DOOR_OPEN,
	DEVICE_IN_USE = ERROR_DEVICE_IN_USE,
	DEVICE_REQUIRES_CLEANING = ERROR_DEVICE_REQUIRES_CLEANING,
	DEV_NOT_EXIST = ERROR_DEV_NOT_EXIST,
	DIRECTORY = ERROR_DIRECTORY,
	DIRECT_ACCESS_HANDLE = ERROR_DIRECT_ACCESS_HANDLE,
	DIR_NOT_EMPTY = ERROR_DIR_NOT_EMPTY,
	DISK_CHANGE = ERROR_DISK_CHANGE,
	DISK_CORRUPT = ERROR_DISK_CORRUPT,
	DISK_FULL = ERROR_DISK_FULL,
	DRIVE_LOCKED = ERROR_DRIVE_LOCKED,
	DS_GENERIC_ERROR = ERROR_DS_GENERIC_ERROR,
	DUP_NAME = ERROR_DUP_NAME,
	EAS_DIDNT_FIT = ERROR_EAS_DIDNT_FIT,
	EAS_NOT_SUPPORTED = ERROR_EAS_NOT_SUPPORTED,
	EA_LIST_INCONSISTENT = ERROR_EA_LIST_INCONSISTENT,
	EA_TABLE_FULL = ERROR_EA_TABLE_FULL,
	END_OF_MEDIA = ERROR_END_OF_MEDIA,
	ENVVAR_NOT_FOUND = ERROR_ENVVAR_NOT_FOUND,
	EOM_OVERFLOW = ERROR_EOM_OVERFLOW,
	EXE_MACHINE_TYPE_MISMATCH = ERROR_EXE_MACHINE_TYPE_MISMATCH,
	EXE_MARKED_INVALID = ERROR_EXE_MARKED_INVALID,
	FAIL_I24 = ERROR_FAIL_I24,
	FILEMARK_DETECTED = ERROR_FILEMARK_DETECTED,
	FILENAME_EXCED_RANGE = ERROR_FILENAME_EXCED_RANGE,
	FILE_CORRUPT = ERROR_FILE_CORRUPT,
	FILE_EXISTS = ERROR_FILE_EXISTS,
	FILE_INVALID = ERROR_FILE_INVALID,
	FILE_NOT_FOUND = ERROR_FILE_NOT_FOUND,
	GEN_FAILURE = ERROR_GEN_FAILURE,
	HANDLE_DISK_FULL = ERROR_HANDLE_DISK_FULL,
	HANDLE_EOF = ERROR_HANDLE_EOF,
	INSUFFICIENT_BUFFER = ERROR_INSUFFICIENT_BUFFER,
	INVALID_ACCESS = ERROR_INVALID_ACCESS,
	INVALID_ADDRESS = ERROR_INVALID_ADDRESS,
	INVALID_AT_INTERRUPT_TIME = ERROR_INVALID_AT_INTERRUPT_TIME,
	INVALID_BLOCK = ERROR_INVALID_BLOCK,
	INVALID_BLOCK_LENGTH = ERROR_INVALID_BLOCK_LENGTH,
	INVALID_DATA = ERROR_INVALID_DATA,
	INVALID_DRIVE = ERROR_INVALID_DRIVE,
	INVALID_EA_NAME = ERROR_INVALID_EA_NAME,
	INVALID_EXE_SIGNATURE = ERROR_INVALID_EXE_SIGNATURE,
	INVALID_FLAGS = ERROR_INVALID_FLAGS,
	INVALID_FUNCTION = ERROR_INVALID_FUNCTION,
	INVALID_HANDLE = ERROR_INVALID_HANDLE,
	INVALID_LOGON_HOURS = ERROR_INVALID_LOGON_HOURS,
	INVALID_NAME = ERROR_INVALID_NAME,
	INVALID_OWNER = ERROR_INVALID_OWNER,
	INVALID_PARAMETER = ERROR_INVALID_PARAMETER,
	INVALID_PASSWORD = ERROR_INVALID_PASSWORD,
	INVALID_PRIMARY_GROUP = ERROR_INVALID_PRIMARY_GROUP,
	INVALID_SIGNAL_NUMBER = ERROR_INVALID_SIGNAL_NUMBER,
	INVALID_TARGET_HANDLE = ERROR_INVALID_TARGET_HANDLE,
	INVALID_WORKSTATION = ERROR_INVALID_WORKSTATION,
	IOPL_NOT_ENABLED = ERROR_IOPL_NOT_ENABLED,
	IO_DEVICE = ERROR_IO_DEVICE,
	IO_INCOMPLETE = ERROR_IO_INCOMPLETE,
	IO_PENDING = ERROR_IO_PENDING,
	LOCKED = ERROR_LOCKED,
	LOCK_FAILED = ERROR_LOCK_FAILED,
	LOCK_VIOLATION = ERROR_LOCK_VIOLATION,
	LOGON_FAILURE = ERROR_LOGON_FAILURE,
	MAPPED_ALIGNMENT = ERROR_MAPPED_ALIGNMENT,
	MAX_THRDS_REACHED = ERROR_MAX_THRDS_REACHED,
	META_EXPANSION_TOO_LONG = ERROR_META_EXPANSION_TOO_LONG,
	MOD_NOT_FOUND = ERROR_MOD_NOT_FOUND,
	MORE_DATA = ERROR_MORE_DATA,
	NEGATIVE_SEEK = ERROR_NEGATIVE_SEEK,
	NESTING_NOT_ALLOWED = ERROR_NESTING_NOT_ALLOWED,
	NETNAME_DELETED = ERROR_NETNAME_DELETED,
	NETWORK_ACCESS_DENIED = ERROR_NETWORK_ACCESS_DENIED,
	NETWORK_BUSY = ERROR_NETWORK_BUSY,
	NET_WRITE_FAULT = ERROR_NET_WRITE_FAULT,
	NOACCESS = ERROR_NOACCESS,
	NONE_MAPPED = ERROR_NONE_MAPPED,
	NONPAGED_SYSTEM_RESOURCES = ERROR_NONPAGED_SYSTEM_RESOURCES,
	NOT_CONNECTED = ERROR_NOT_CONNECTED,
	NOT_DOS_DISK = ERROR_NOT_DOS_DISK,
	NOT_ENOUGH_MEMORY = ERROR_NOT_ENOUGH_MEMORY,
	NOT_ENOUGH_QUOTA = ERROR_NOT_ENOUGH_QUOTA,
	NOT_LOCKED = ERROR_NOT_LOCKED,
	NOT_OWNER = ERROR_NOT_OWNER,
	NOT_READY = ERROR_NOT_READY,
	NOT_SAME_DEVICE = ERROR_NOT_SAME_DEVICE,
	NOT_SUPPORTED = ERROR_NOT_SUPPORTED,
	NO_DATA = ERROR_NO_DATA,
	NO_DATA_DETECTED = ERROR_NO_DATA_DETECTED,
	NO_MEDIA_IN_DRIVE = ERROR_NO_MEDIA_IN_DRIVE,
	NO_MORE_FILES = ERROR_NO_MORE_FILES,
	NO_MORE_SEARCH_HANDLES = ERROR_NO_MORE_SEARCH_HANDLES,
	NO_PROC_SLOTS = ERROR_NO_PROC_SLOTS,
	NO_SIGNAL_SENT = ERROR_NO_SIGNAL_SENT,
	NO_SPOOL_SPACE = ERROR_NO_SPOOL_SPACE,
	NO_SUCH_PRIVILEGE = ERROR_NO_SUCH_PRIVILEGE,
	NO_SYSTEM_RESOURCES = ERROR_NO_SYSTEM_RESOURCES,
	NO_TOKEN = ERROR_NO_TOKEN,
	OPEN_FAILED = ERROR_OPEN_FAILED,
	OPEN_FILES = ERROR_OPEN_FILES,
	OPERATION_ABORTED = ERROR_OPERATION_ABORTED,
	OUTOFMEMORY = ERROR_OUTOFMEMORY,
	OUT_OF_PAPER = ERROR_OUT_OF_PAPER,
	OUT_OF_STRUCTURES = ERROR_OUT_OF_STRUCTURES,
	PAGED_SYSTEM_RESOURCES = ERROR_PAGED_SYSTEM_RESOURCES,
	PAGEFILE_QUOTA = ERROR_PAGEFILE_QUOTA,
	PASSWORD_EXPIRED = ERROR_PASSWORD_EXPIRED,
	PATH_BUSY = ERROR_PATH_BUSY,
	PATH_NOT_FOUND = ERROR_PATH_NOT_FOUND,
	PIPE_BUSY = ERROR_PIPE_BUSY,
	PIPE_CONNECTED = ERROR_PIPE_CONNECTED,
	PIPE_LISTENING = ERROR_PIPE_LISTENING,
	PIPE_NOT_CONNECTED = ERROR_PIPE_NOT_CONNECTED,
	POSSIBLE_DEADLOCK = ERROR_POSSIBLE_DEADLOCK,
	PRINTQ_FULL = ERROR_PRINTQ_FULL,
	PRINT_CANCELLED = ERROR_PRINT_CANCELLED,
	PRIVILEGE_NOT_HELD = ERROR_PRIVILEGE_NOT_HELD,
	PROCESS_ABORTED = ERROR_PROCESS_ABORTED,
	PROC_NOT_FOUND = ERROR_PROC_NOT_FOUND,
	READ_FAULT = ERROR_READ_FAULT,
	REDIR_PAUSED = ERROR_REDIR_PAUSED,
	REM_NOT_LIST = ERROR_REM_NOT_LIST,
	REQ_NOT_ACCEP = ERROR_REQ_NOT_ACCEP,
	SECTOR_NOT_FOUND = ERROR_SECTOR_NOT_FOUND,
	SEEK = ERROR_SEEK,
	SEEK_ON_DEVICE = ERROR_SEEK_ON_DEVICE,
	SERVICE_REQUEST_TIMEOUT = ERROR_SERVICE_REQUEST_TIMEOUT,
	SETMARK_DETECTED = ERROR_SETMARK_DETECTED,
	SHARING_BUFFER_EXCEEDED = ERROR_SHARING_BUFFER_EXCEEDED,
	SHARING_PAUSED = ERROR_SHARING_PAUSED,
	SHARING_VIOLATION = ERROR_SHARING_VIOLATION,
	SIGNAL_PENDING = ERROR_SIGNAL_PENDING,
	SIGNAL_REFUSED = ERROR_SIGNAL_REFUSED,
	STACK_OVERFLOW = ERROR_STACK_OVERFLOW,
	SWAPERROR = ERROR_SWAPERROR,
	SXS_CANT_GEN_ACTCTX = ERROR_SXS_CANT_GEN_ACTCTX,
	THREAD_1_INACTIVE = ERROR_THREAD_1_INACTIVE,
	TIMEOUT = ERROR_TIMEOUT,
	TOO_MANY_CMDS = ERROR_TOO_MANY_CMDS,
	TOO_MANY_LINKS = ERROR_TOO_MANY_LINKS,
	TOO_MANY_MODULES = ERROR_TOO_MANY_MODULES,
	TOO_MANY_NAMES = ERROR_TOO_MANY_NAMES,
	TOO_MANY_OPEN_FILES = ERROR_TOO_MANY_OPEN_FILES,
	TOO_MANY_SESS = ERROR_TOO_MANY_SESS,
	UNEXP_NET_ERR = ERROR_UNEXP_NET_ERR,
	UNRECOGNIZED_MEDIA = ERROR_UNRECOGNIZED_MEDIA,
	UNRECOGNIZED_VOLUME = ERROR_UNRECOGNIZED_VOLUME,
	WAIT_NO_CHILDREN = ERROR_WAIT_NO_CHILDREN,
	WORKING_SET_QUOTA = ERROR_WORKING_SET_QUOTA,
	WRITE_FAULT = ERROR_WRITE_FAULT,
	WRITE_PROTECT = ERROR_WRITE_PROTECT,
	WRONG_DISK = ERROR_WRONG_DISK
    };

    export auto operator +(WindowsError err)->std::underlying_type<WindowsError>::type;
    export auto windows_error(DWORD dwLastError = ::GetLastError()) -> WindowsError;
    export auto windows_error_code(DWORD dwLastError = ::GetLastError()) -> std::error_code;
    export auto make_error_code(odbc::WindowsError dwLastError) -> std::error_code;

    export ODBCXX_EXPORT class ODBCXX_EXPORT WindowsCategory: public std::error_category
    {
    public:
	virtual char const *name() const noexcept override;
	virtual std::error_condition default_error_condition(int ev) const noexcept override;
	virtual bool equivalent(int code, std::error_condition const &condition) const noexcept;
	// virtual bool equivalent(std::error_code const &code, int condition) const noexcept;
	virtual std::string message(int ev) const override;
    }
    const &windows_category();
}

namespace std
{
    template <>
    struct is_error_code_enum<odbc::WindowsError>: true_type
    {
    };
}

inline auto odbc::make_error_code(odbc::WindowsError dwLastError) -> std::error_code
{
    return std::error_code(static_cast<int>(dwLastError), odbc::windows_category());
}

inline auto odbc::WindowsCategory::name() const noexcept -> char const *
{
    return "Windows";
}

inline auto odbc::WindowsCategory::equivalent(int code, std::error_condition const &condition) const noexcept -> bool
{
    return std::error_condition(code, windows_category()) == condition || default_error_condition(code) == condition;
}

inline auto odbc::operator +(WindowsError err) -> std::underlying_type<odbc::WindowsError>::type
{
    return static_cast<std::underlying_type<odbc::WindowsError>::type>(err);
}

inline auto odbc::windows_error(DWORD dwLastError) -> odbc::WindowsError
{
    return static_cast<WindowsError>(dwLastError);
}

inline auto odbc::windows_error_code(DWORD dwLastError) -> std::error_code
{
    return make_error_code(windows_error(dwLastError));
}

module :private;

using std::string;
using std::to_string;
using std::error_condition;
using std::generic_category;
using std::unique_ptr;
using std::exchange;
using namespace std::literals::string_literals;;

odbc::WindowsCategory const &odbc::windows_category()
{
    static WindowsCategory windowsCategory;

    return windowsCategory;
}

error_condition odbc::WindowsCategory::default_error_condition(int ev) const noexcept
{
    if (ev == ERROR_SUCCESS)
	return error_condition(0, generic_category());

    int error = ERROR_SUCCESS;

    switch (ev)
    {
	case ERROR_ACCESS_DENIED:		error = EACCES;		break;
	case ERROR_ACCOUNT_DISABLED:		error = EACCES;		break;
	case ERROR_ACCOUNT_RESTRICTION:		error = EACCES;		break;
	case ERROR_ACTIVE_CONNECTIONS:		error = EAGAIN;		break;
	case ERROR_ADAP_HDW_ERR:                error = EIO;            break;
	case ERROR_ALREADY_ASSIGNED:		error = EBUSY;		break;
	case ERROR_ALREADY_EXISTS:		error = EEXIST;		break;
	case ERROR_ARENA_TRASHED:		error = ENOMEM;		break;
	case ERROR_ARITHMETIC_OVERFLOW:		error = ERANGE;		break;
	case ERROR_BAD_COMMAND:			error = EIO;		break;
	case ERROR_BAD_DEVICE:			error = ENODEV;		break;
	case ERROR_BAD_DEV_TYPE:                error = ENODEV;         break;
	case ERROR_BAD_DRIVER_LEVEL:		error = ENXIO;		break;
	case ERROR_BAD_ENVIRONMENT:		error = E2BIG;		break;
	case ERROR_BAD_EXE_FORMAT:		error = ENOEXEC;	break;
	case ERROR_BAD_FORMAT:			error = ENOEXEC;	break;
	case ERROR_BAD_LENGTH:			error = EINVAL;		break;
	case ERROR_BAD_NETPATH:			error = ENOENT;		break;
	case ERROR_BAD_NET_NAME:		error = ENOENT;		break;
	case ERROR_BAD_NET_RESP:                error = EIO;            break;
	case ERROR_BAD_PATHNAME:		error = ENOENT;		break;
	case ERROR_BAD_PIPE:			error = EPIPE;		break;
	case ERROR_BAD_REM_ADAP:                error = EINVAL;         break;
	case ERROR_BAD_UNIT:			error = ENODEV;		break;
	case ERROR_BAD_USERNAME:		error = EINVAL;		break;
	case ERROR_BEGINNING_OF_MEDIA:		error = EIO;		break;
	case ERROR_BROKEN_PIPE:			error = EPIPE;		break;
	case ERROR_BUFFER_OVERFLOW:             error = ENOBUFS;        break;
	case ERROR_BUSY:			error = EBUSY;		break;
	case ERROR_BUSY_DRIVE:			error = EBUSY;		break;
	case ERROR_BUS_RESET:			error = EIO;		break;
	case ERROR_CALL_NOT_IMPLEMENTED:	error = ENOSYS;		break;
	case ERROR_CANCELLED:			error = EINTR;		break;
	case ERROR_CANNOT_MAKE:			error = EIO;		break;
	case ERROR_CANTOPEN:			error = EIO;		break;
	case ERROR_CANTREAD:			error = EIO;		break;
	case ERROR_CANTWRITE:			error = EIO;		break;
	case ERROR_CHILD_NOT_COMPLETE:		error = ECHILD;		break;
	case ERROR_COMMITMENT_LIMIT:		error = EAGAIN;		break;
	case ERROR_CONNECTION_REFUSED:		error = ECONNREFUSED;	break;
	case ERROR_CRC:				error = EIO;		break;
	case ERROR_CURRENT_DIRECTORY:		error = EACCES;		break;
	case ERROR_DEVICE_DOOR_OPEN:		error = EIO;		break;
	case ERROR_DEVICE_IN_USE:		error = EBUSY;		break;
	case ERROR_DEVICE_REQUIRES_CLEANING:	error = EIO;		break;
	case ERROR_DEV_NOT_EXIST:		error = ENODEV;		break;
	case ERROR_DIRECTORY:			error = ENOTDIR;	break;
	case ERROR_DIRECT_ACCESS_HANDLE:	error = EBADF;		break;
	case ERROR_DIR_NOT_EMPTY:		error = ENOTEMPTY;	break;
	case ERROR_DISK_CHANGE:                 error = EXDEV;          break;
	case ERROR_DISK_CORRUPT:		error = EIO;		break;
	case ERROR_DISK_FULL:			error = ENOSPC;		break;
	case ERROR_DRIVE_LOCKED:		error = EBUSY;		break;
	case ERROR_DS_GENERIC_ERROR:		error = EIO;		break;
	case ERROR_DUP_NAME:			error = EEXIST;		break;
	case ERROR_EAS_DIDNT_FIT:		error = ENOSPC;		break;
	case ERROR_EAS_NOT_SUPPORTED:		error = ENOTSUP;	break;
	case ERROR_EA_LIST_INCONSISTENT:	error = EINVAL;		break;
	case ERROR_EA_TABLE_FULL:		error = ENOSPC;		break;
	case ERROR_END_OF_MEDIA:		error = ENOSPC;		break;
	case ERROR_ENVVAR_NOT_FOUND:		error = EINVAL;		break;
	case ERROR_EOM_OVERFLOW:		error = EIO;		break;
	case ERROR_EXE_MACHINE_TYPE_MISMATCH:	error = ENOEXEC;	break;
	case ERROR_EXE_MARKED_INVALID:		error = ENOEXEC;	break;
	case ERROR_FAIL_I24:                    error = EIO;            break;
	case ERROR_FILEMARK_DETECTED:		error = EIO;		break;
	case ERROR_FILENAME_EXCED_RANGE:	error = ENAMETOOLONG;	break;
	case ERROR_FILE_CORRUPT:		error = EINVAL;		break;
	case ERROR_FILE_EXISTS:			error = EEXIST;		break;
	case ERROR_FILE_INVALID:		error = ENXIO;		break;
	case ERROR_FILE_NOT_FOUND:		error = ENOENT;		break;
	case ERROR_GEN_FAILURE:			error = EIO;		break;
	case ERROR_HANDLE_DISK_FULL:		error = ENOSPC;		break;
	case ERROR_HANDLE_EOF:			error = ENODATA;	break;
	case ERROR_INSUFFICIENT_BUFFER:		error = ENOBUFS;	break;
	case ERROR_INVALID_ACCESS:		error = EINVAL;		break;
	case ERROR_INVALID_ADDRESS:		error = EINVAL;		break;
	case ERROR_INVALID_AT_INTERRUPT_TIME:	error = EINTR;		break;
	case ERROR_INVALID_BLOCK:		error = EFAULT;		break;
	case ERROR_INVALID_BLOCK_LENGTH:	error = EIO;		break;
	case ERROR_INVALID_DATA:		error = EINVAL;		break;
	case ERROR_INVALID_DRIVE:		error = ENODEV;		break;
	case ERROR_INVALID_EA_NAME:		error = EINVAL;		break;
	case ERROR_INVALID_EXE_SIGNATURE:	error = ENOEXEC;	break;
	case ERROR_INVALID_FLAGS:		error = EINVAL;		break;
	case ERROR_INVALID_FUNCTION:		error = ENOSYS;		break;
	case ERROR_INVALID_HANDLE:		error = EBADF;		break;
	case ERROR_INVALID_LOGON_HOURS:		error = EACCES;		break;
	case ERROR_INVALID_NAME:		error = EINVAL;		break;
	case ERROR_INVALID_OWNER:		error = EINVAL;		break;
	case ERROR_INVALID_PARAMETER:		error = EINVAL;		break;
	case ERROR_INVALID_PASSWORD:		error = EPERM;		break;
	case ERROR_INVALID_PRIMARY_GROUP:	error = EINVAL;		break;
	case ERROR_INVALID_SIGNAL_NUMBER:	error = EINVAL;		break;
	case ERROR_INVALID_TARGET_HANDLE:	error = EBADF;		break;
	case ERROR_INVALID_WORKSTATION:		error = EACCES;		break;
	case ERROR_IOPL_NOT_ENABLED:		error = ENOEXEC;	break;
	case ERROR_IO_DEVICE:			error = EIO;		break;
	case ERROR_IO_INCOMPLETE:		error = EINTR;		break;
	case ERROR_IO_PENDING:			error = EAGAIN;		break;
	case ERROR_LOCKED:			error = EBUSY;		break;
	case ERROR_LOCK_FAILED:			error = EACCES;		break;
	case ERROR_LOCK_VIOLATION:		error = EBUSY;		break;
	case ERROR_LOGON_FAILURE:		error = EACCES;		break;
	case ERROR_MAPPED_ALIGNMENT:		error = EINVAL;		break;
	case ERROR_MAX_THRDS_REACHED:		error = EAGAIN;		break;
	case ERROR_META_EXPANSION_TOO_LONG:	error = E2BIG;		break;
	case ERROR_MOD_NOT_FOUND:		error = ENOENT;		break;
	case ERROR_MORE_DATA:			error = EMSGSIZE;	break;
	case ERROR_NEGATIVE_SEEK:		error = EINVAL;		break;
	case ERROR_NESTING_NOT_ALLOWED:		error = EINPROGRESS;	break;
	case ERROR_NETNAME_DELETED:		error = ENOENT;		break;
	case ERROR_NETWORK_ACCESS_DENIED:	error = EACCES;		break;
	case ERROR_NETWORK_BUSY:                error = EBUSY;          break;
	case ERROR_NET_WRITE_FAULT:             error = EIO;            break;
	case ERROR_NOACCESS:			error = EFAULT;		break;
	case ERROR_NONE_MAPPED:			error = EINVAL;		break;
	case ERROR_NONPAGED_SYSTEM_RESOURCES:	error = EAGAIN;		break;
	case ERROR_NOT_CONNECTED:		error = ENOLINK;	break;
	case ERROR_NOT_DOS_DISK:                error = EIO;            break;
	case ERROR_NOT_ENOUGH_MEMORY:		error = ENOMEM;		break;
	case ERROR_NOT_ENOUGH_QUOTA:		error = ENOMEM;		break;
	case ERROR_NOT_LOCKED:			error = EACCES;		break;
	case ERROR_NOT_OWNER:			error = EPERM;		break;
	case ERROR_NOT_READY:			error = EAGAIN;		break;
	case ERROR_NOT_SAME_DEVICE:		error = EXDEV;		break;
	case ERROR_NOT_SUPPORTED:		error = ENOSYS;		break;
	case ERROR_NO_DATA:			error = EPIPE;		break;
	case ERROR_NO_DATA_DETECTED:		error = EIO;		break;
	case ERROR_NO_MEDIA_IN_DRIVE:		error = EAGAIN;		break;
	case ERROR_NO_MORE_FILES:		error = ENOENT;		break;
	case ERROR_NO_MORE_SEARCH_HANDLES:	error = ENFILE;		break;
	case ERROR_NO_PROC_SLOTS:		error = EAGAIN;		break;
	case ERROR_NO_SIGNAL_SENT:		error = EIO;		break;
	case ERROR_NO_SPOOL_SPACE:              error = ENOBUFS;        break;
	case ERROR_NO_SUCH_PRIVILEGE:		error = EACCES;		break;
	case ERROR_NO_SYSTEM_RESOURCES:		error = EFBIG;		break;
	case ERROR_NO_TOKEN:			error = EINVAL;		break;
	case ERROR_OPEN_FAILED:			error = EIO;		break;
	case ERROR_OPEN_FILES:			error = EBUSY;		break;
	case ERROR_OPERATION_ABORTED:		error = EINTR;		break;
	case ERROR_OUTOFMEMORY:			error = ENOMEM;		break;
	case ERROR_OUT_OF_PAPER:                error = EAGAIN;         break;
	case ERROR_OUT_OF_STRUCTURES:           error = ENFILE;         break;
	case ERROR_PAGED_SYSTEM_RESOURCES:	error = EAGAIN;		break;
	case ERROR_PAGEFILE_QUOTA:		error = EAGAIN;		break;
	case ERROR_PASSWORD_EXPIRED:		error = EACCES;		break;
	case ERROR_PATH_BUSY:			error = EBUSY;		break;
	case ERROR_PATH_NOT_FOUND:		error = ENOENT;		break;
	case ERROR_PIPE_BUSY:			error = EBUSY;		break;
	case ERROR_PIPE_CONNECTED:		error = EBUSY;		break;
	case ERROR_PIPE_LISTENING:		error = EIO;		break;
	case ERROR_PIPE_NOT_CONNECTED:          error = EPIPE;          break;
	case ERROR_POSSIBLE_DEADLOCK:		error = EDEADLOCK;	break;
	case ERROR_PRINTQ_FULL:                 error = ENOBUFS;        break;
	case ERROR_PRINT_CANCELLED:             error = ECANCELED;      break;
	case ERROR_PRIVILEGE_NOT_HELD:		error = EPERM;		break;
	case ERROR_PROCESS_ABORTED:		error = EFAULT;		break;
	case ERROR_PROC_NOT_FOUND:              error = EINVAL;         break;
	case ERROR_READ_FAULT:			error = EIO;		break;
	case ERROR_REDIR_PAUSED:                error = EAGAIN;         break;
	case ERROR_REM_NOT_LIST:		error = ENOENT;		break;
	case ERROR_REQ_NOT_ACCEP:               error = EBUSY;          break;
	case ERROR_SECTOR_NOT_FOUND:            error = ENXIO;          break;
	case ERROR_SEEK:                        error = EIO;            break;
	case ERROR_SEEK_ON_DEVICE:		error = ESPIPE;		break;
	case ERROR_SERVICE_REQUEST_TIMEOUT:	error = ETIMEDOUT;	break;
	case ERROR_SETMARK_DETECTED:		error = EIO;		break;
	case ERROR_SHARING_BUFFER_EXCEEDED:	error = ENOBUFS;	break;
	case ERROR_SHARING_PAUSED:              error = EAGAIN;         break;
	case ERROR_SHARING_VIOLATION:		error = EBUSY;		break;
	case ERROR_SIGNAL_PENDING:		error = EBUSY;		break;
	case ERROR_SIGNAL_REFUSED:		error = EIO;		break;
	case ERROR_STACK_OVERFLOW:		error = ENOMEM;		break;
	case ERROR_SWAPERROR:			error = ENOENT;		break;
	case ERROR_SXS_CANT_GEN_ACTCTX:		error = EIO;		break;
	case ERROR_THREAD_1_INACTIVE:		error = EINVAL;		break;
	case ERROR_TIMEOUT:			error = ETIMEDOUT;	break;
	case ERROR_TOO_MANY_CMDS:               error = EAGAIN;         break;
	case ERROR_TOO_MANY_LINKS:		error = EMLINK;		break;
	case ERROR_TOO_MANY_MODULES:		error = EMFILE;		break;
	case ERROR_TOO_MANY_NAMES:              error = ENFILE;         break;
	case ERROR_TOO_MANY_OPEN_FILES:		error = EMFILE;		break;
	case ERROR_TOO_MANY_SESS:               error = EIO;            break;
	case ERROR_UNEXP_NET_ERR:		error = EIO;		break;
	case ERROR_UNRECOGNIZED_MEDIA:		error = ENXIO;		break;
	case ERROR_UNRECOGNIZED_VOLUME:		error = ENODEV;		break;
	case ERROR_WAIT_NO_CHILDREN:		error = ECHILD;		break;
	case ERROR_WORKING_SET_QUOTA:		error = EAGAIN;		break;
	case ERROR_WRITE_FAULT:			error = EIO;		break;
	case ERROR_WRITE_PROTECT:		error = EROFS;		break;
	case ERROR_WRONG_DISK:                  error = ENXIO;          break;
    }

    if (error == ERROR_SUCCESS)
	return error_condition(ev, windows_category());
    else
	return error_condition(error, generic_category());
}

string odbc::WindowsCategory::message(int ev) const
{
    HLOCAL pMessage = NULL;

    unique_ptr<HLOCAL, void (*)(HLOCAL *)> cleanUpHandle { &pMessage, [](HLOCAL *pp)
	    {
		if (*pp)
		    ::LocalFree(exchange(*pp, HLOCAL { NULL }));
	    } };

    DWORD dwCharCount =
	::FormatMessageA
	    (
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		static_cast<DWORD>(ev),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		static_cast<LPSTR>(static_cast<void *>(&pMessage)),
		0u,
		NULL
	    );

    if (!dwCharCount)
	return "(Failed to format message for Windows API error "s + to_string(static_cast<DWORD>(ev)) + ')';

    string errorMessage { static_cast<char const *>(pMessage), dwCharCount };

    while (errorMessage.size() && (errorMessage.back() == '\n' || errorMessage.back() == '\r'))
	errorMessage.pop_back();

    return errorMessage;
}
