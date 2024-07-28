/*
 * Do not include this header if you needn't it!
 */
#pragma once
#include "fractions.h"

#ifdef __cplusplus
extern "C" {
#endif



MF__OVERLOAD_RARES(MF__DEFINE__GCD)
MF__OVERLOAD_RARES(MF__DEFINE__LCM)

MF__OVERLOAD_RARES(MF__DEFINE__fraction_struct)
MF__OVERLOAD_RARES(MF__DEFINE__alloc_fraction)
MF__OVERLOAD_RARES(MF__DEFINE__get_look_of_fraction)
MF__OVERLOAD_RARES(MF__DEFINE__stringify_fraction)
MF__OVERLOAD_RARES(MF__DEFINE__extract_integer)
MF__OVERLOAD_RARES(MF__DEFINE__extract_fractional)
MF__OVERLOAD_RARES(MF__DEFINE__multiply_denominator)
MF__OVERLOAD_RARES(MF__DEFINE__reduce_fraction)
MF__OVERLOAD_RARES(MF__DEFINE__convert_to_same_look)

MF__OVERLOAD_RARES(MF__DEFINE__ALL_MATH_OPERATORS)
MF__OVERLOAD_RARES(MF__DEFINE__ALL_COMPARISON_OPERATORS)



#ifdef __cplusplus
}
#endif

/* enjoy the code size :) */
