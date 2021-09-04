//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/CPPAlliance/url
//

#ifndef BOOST_URL_RFC_AUTHORITY_HPP
#define BOOST_URL_RFC_AUTHORITY_HPP

#include <boost/url/detail/config.hpp>
#include <boost/url/error.hpp>
#include <boost/url/rfc/host.hpp>
#include <boost/url/rfc/port.hpp>
#include <boost/url/rfc/userinfo.hpp>
#include <boost/optional.hpp>
#include <array>
#include <cstdint>

namespace boost {
namespace urls {
namespace rfc {

/** BNF for authority

    @par BNF
    @code
    authority   = [ userinfo "@" ] host [ ":" port ]
    @endcode

    @see
        https://datatracker.ietf.org/doc/html/rfc3986#section-3.2
*/
class authority
{
    rfc::host h_;
    optional<rfc::port> p_;
    optional<rfc::userinfo> u_;

public:
    optional<
        rfc::userinfo> const&
    userinfo() const noexcept
    {
        return u_;
    }

    rfc::host const&
    host() const noexcept
    {
        return h_;
    }

    optional<rfc::port> const&
    port() const noexcept
    {
        return p_;
    }

    BOOST_URL_DECL
    friend
    char const*
    parse(
        char const* const start,
        char const* const end,
        error_code& ec,
        authority& t);
};

} // rfc
} // urls
} // boost

#endif
