//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/secd.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/sqrt_2.hpp>


namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : -T(i);
    b[i] = bs::secd(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::secd(aa1), bb, 0.5);
}

STF_CASE_TPL("Check secd saturated on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}


STF_CASE_TPL (" secd",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::secd;

  using r_t = decltype(secd(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(secd(-T(90)), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(T(90)), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(secd(-T(180)), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(-T(45)), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(bs::Zero<T>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(T(180)), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(T(45)), bs::Sqrt_2<r_t>(), 0.5);
}

STF_CASE_TPL (" secd",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::secd;
  using p_t = bs::pack<T>;

  using r_t = decltype(secd(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(secd(-p_t(90)), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(bs::Inf<p_t>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(bs::Minf<p_t>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(bs::Nan<p_t>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(p_t(90)), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(secd(-p_t(180)), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(-p_t(45)), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(bs::Zero<p_t>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(p_t(180)), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(secd(p_t(45)), bs::Sqrt_2<r_t>(), 0.5);
}

