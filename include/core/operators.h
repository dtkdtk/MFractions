#pragma once
#include "config.h"
#include "core.h"
#include "overloads.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif



/// Warning: 'type' param should not contain spaces
/// Warning: Possibility of variable overflow
#define MF__DEFINE__MATH_OPERATOR(type, op, opname)                          \
inline MF__(fraction_##type##_t) MF__(opname##_fractions__##type)(MF__(fraction_##type##_t) a,\
                                                                  MF__(fraction_##type##_t) b)\
{                                                                            \
    MF__(fraction_##type##_t) result = {0, 0, 0};                            \
    MF__(convert_to_same_look__##type)(&a, &b);                              \
    result.numerator = a.numerator op b.numerator;                           \
    return result;                                                           \
}                                                                            //

#define MF__DEFINE__MOD_OPERATOR(type) MF__DEFINE__MATH_OPERATOR(type, %, mod)



/// internal @internal
/// Warning: 'type' param should not contain spaces
#define MF__DEFINE__COMPARISON_OPERATOR(type, op, opname)                   \
inline bool MF__(fractions_##opname##__##type)(MF__(fraction_##type##_t) a, \
                                              MF__(fraction_##type##_t) b)  \
{                                                                           \
    MF__(convert_to_same_look__##type)(&a, &b);                             \
    return a.numerator op b.numerator;                                      \
}                                                                           //



/// internal @internal
#define __MF__MATH_OPS(generator, type)    \
    generator(type, +    , sum)            \
    generator(type, -    , sub)            \
    generator(type, *    , mul)            \
    generator(type, /    , div)            //

/// internal @internal
#define __MF__COMPARISON_OPS(generator, type)       \
    generator(type, ==    , eq)                     \
    generator(type, !=    , neq)                    \
    generator(type, >    , greater)                 \
    generator(type, <    , less)                    \
    generator(type, >=    , greater_eq)             \
    generator(type, <=    , less_eq)                //

#define MF__DEFINE__ALL_MATH_OPERATORS(type) __MF__MATH_OPS(MF__DEFINE__MATH_OPERATOR, type)
#define MF__DEFINE__ALL_COMPARISON_OPERATORS(type) __MF__COMPARISON_OPS(MF__DEFINE__COMPARISON_OPERATOR, type)

//The full macro causes severe Visual Studio lag. I had to separate it
MF__OVERLOAD_DEFAULTS(MF__DEFINE__ALL_MATH_OPERATORS)
MF__OVERLOAD_DEFAULTS(MF__DEFINE__ALL_COMPARISON_OPERATORS)
MF__OVERLOAD_DEFAULTS(MF__DEFINE__MOD_OPERATOR)



#ifdef __cplusplus
}  //extern "C"
#endif
