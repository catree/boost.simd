## --------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                    Distributed under the Boost Software License Version 1.0
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## --------------------------------------------------------------------------------------

## benches for functor firstbitset in simd mode.

set(SOURCES
  regular.float.m10_10.cpp
  regular.double.m10_10.cpp
  regular.int16_t.m10_10.cpp
  regular.int32_t.m10_10.cpp
  regular.int64_t.m10_10.cpp
  regular.int8_t.m10_10.cpp
  regular.uint16_t.0_10.cpp
  regular.uint32_t.0_10.cpp
  regular.uint64_t.0_10.cpp
  regular.uint8_t.0_10.cpp
)

make_bench("function.simd.firstbitset" ${SOURCES})

## --------------------------------------------------------------------------------------
