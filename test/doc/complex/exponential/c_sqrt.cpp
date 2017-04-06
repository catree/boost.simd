//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [sqrt]
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/sqrt.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/pi.hpp>
#include <iostream>

namespace bs = boost::simd;
using p_t  = bs::pack<float, 4>;
using cp_t = bs::complex<p_t>;

int main() {
  cp_t pf{p_t{1.0f, 2.0f, -1.0f, 0.5f}, p_t{0.0, 1.0, -1.0, 3.0}};

  std::cout << "---- simd" << '\n'
            << "<- pf =           " << pf << '\n'
            << "-> bs::sqrt(pf) = " << bs::sqrt(pf) << '\n';

  bs::complex<float> xf{0.0, bs::Pi<float>()};
  float yf{-1.0};

  std::cout << "---- scalar" << '\n'
            << "<- xf =                  " << xf << '\n'
            << "-> bs::sqrt(xf) =        " << bs::sqrt(xf) << '\n'
            << "<- yf =                  " << yf << '\n'
            << "-> bs::sqrt(yf) =        " << bs::sqrt(yf) << '\n'
            << "-> bs::cmplx::sqrt(yf) = " << bs::cmplx::sqrt(yf) << '\n';

  return 0;
}
//! [sqrt]