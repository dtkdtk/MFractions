#pragma once
#include "config.h"
#include "overloads.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif



#define MF__ASSERT_PTR_NONNULL(ptr) if (ptr == NULL) mf__throw_nullptr_exception(__func__);



/// Throws Null Pointer Exception (NPE)
/// @param func_name Name of the function where the error occurred
MF__NORETURN void mf__throw_nullptr_exception(const char* func_name)
{
    fprintf(stderr, "Error: null pointer exception at function '%s'\n", func_name);
    exit(-1);
}



/// Greatest Common Divisor (GCD)
/// Warning: 'type' param should not contain spaces
#define MF__DEFINE__GCD(type)                   \
inline type MF__(GCD__##type)(type a, type b)   \
{                                               \
    while (a != b)                              \
        if (a > b)                              \
            a -= b;                             \
        else                                    \
            b -= a;                             \
    return a;                                   \
}                                               //
MF__OVERLOAD_DEFAULTS(MF__DEFINE__GCD)



/// Least Common Multiple (LCM)
/// Warning: 'type' param should not contain spaces
#define MF__DEFINE__LCM(type)                    \
inline type MF__(LCM__##type)(type a, type b)    \
{                                                \
    return (a * b) / MF__(GCD__##type)(a, b);    \
}                                                //
MF__OVERLOAD_DEFAULTS(MF__DEFINE__LCM)



#ifdef __cplusplus
}  //extern "C"
#endif
