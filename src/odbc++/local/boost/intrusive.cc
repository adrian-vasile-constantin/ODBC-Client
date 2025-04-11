module;

#include <boost/intrusive/any_hook.hpp>
#include <boost/intrusive/slist.hpp>
#include <boost/intrusive/list.hpp>
#include <boost/intrusive/set.hpp>
#include <boost/intrusive/parent_from_member.hpp>

export module local.boost.intrusive;

namespace local
{
    namespace boost
    {
	namespace intrusive
	{
	    export using ::boost::intrusive::tag;
	    export using ::boost::intrusive::link_mode;
	    export using ::boost::intrusive::void_pointer;
	    export using ::boost::intrusive::constant_time_size;
	    export using ::boost::intrusive::size_type;

	    export using ::boost::intrusive::dft_tag;
	    export using ::boost::intrusive::member_tag;

	    export using ::boost::intrusive::normal_link;
	    export using ::boost::intrusive::safe_link;
	    export using ::boost::intrusive::auto_unlink;

	    export using ::boost::intrusive::get_parent_from_member;

	    export using ::boost::intrusive::key_of_value;
	    export using ::boost::intrusive::priority_of_value;
	    export using ::boost::intrusive::any_base_hook;
	    export using ::boost::intrusive::any_member_hook;
	    export using ::boost::intrusive::function_hook;

	    export using ::boost::intrusive::slist_base_hook;
	    export using ::boost::intrusive::slist_member_hook;
	    export using ::boost::intrusive::slist;

	    export using ::boost::intrusive::list_base_hook;
	    export using ::boost::intrusive::list_member_hook;
	    export using ::boost::intrusive::list;

	    export using ::boost::intrusive::set_base_hook;
	    export using ::boost::intrusive::set_member_hook;
	    export using ::boost::intrusive::set;
	    export using ::boost::intrusive::multiset;

	    namespace detail
	    {
		export using ::boost::intrusive::detail::destructor_impl;
	    }
	}
    }
}

export namespace ext = local;
