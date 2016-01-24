//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_ONEO_8_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_ONEO_8_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct oneo_8_ : boost::dispatch::constant_value_<oneo_8_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,oneo_8_,boost::dispatch::constant_value_<oneo_8_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x3e000000UL, 0x3fc0000000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,oneo_8_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::oneo_8_,oneo_8);
  }

  template<typename T> BOOST_FORCEINLINE auto Oneo_8() BOOST_NOEXCEPT
  -> decltype(functional::oneo_8( boost::dispatch::as_<T>{}))
  {
    return functional::oneo_8( boost::dispatch::as_<T>{} );
  }
} }

#endif