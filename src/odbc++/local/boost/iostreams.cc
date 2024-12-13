module;

#include <boost/iostreams/stream_buffer.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/filter/newline.hpp>

export module local.boost.iostreams;

namespace local::boost::iostreams
{
    export using ::boost::iostreams::closable_tag;
    export using ::boost::iostreams::device_tag;
    export using ::boost::iostreams::input_seekable;
    export using ::boost::iostreams::output_seekable;
    export using ::boost::iostreams::stream_offset;
    export using ::boost::iostreams::file_descriptor;
    export using ::boost::iostreams::stream_buffer;
    export using ::boost::iostreams::basic_file;
    export using ::boost::iostreams::newline_filter;
    export using ::boost::iostreams::filtering_streambuf;
    export using ::boost::iostreams::input;
    export using ::boost::iostreams::output;
    export using ::boost::iostreams::pipeline;
    export using ::boost::iostreams::operator |;

    namespace newline
    {
	export auto const CR = ::boost::iostreams::newline::CR;
	export auto const LF = ::boost::iostreams::newline::LF;

	export auto const posix		= ::boost::iostreams::newline::posix;
	export auto const mac		= ::boost::iostreams::newline::mac;
	export auto const dos		= ::boost::iostreams::newline::dos;
	export auto const mixed		= ::boost::iostreams::newline::mixed;
	export auto const final_newline = ::boost::iostreams::newline::final_newline;
	export auto const platform_mask = ::boost::iostreams::newline::platform_mask;

    }
}

export namespace ext = local;
