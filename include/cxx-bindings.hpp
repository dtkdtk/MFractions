#pragma once
#include "fractions.h"
#include "rare-overloads.h"
#include <string>



namespace mf
{



template <typename _Ty>
struct fraction_data
{
    _Ty numerator;
    _Ty denominator;
    _Ty integer;
};



namespace internal
{



#define MF__DEFINE__fadapter(type)      \
union fadapter_##type                   \
{                                       \
    fraction_data<type> in;             \
    MF__(fraction_##type##_t) out;      \
};                                      //
MF__OVERLOAD_DEFAULTS(MF__DEFINE__fadapter)
MF__OVERLOAD_RARES(MF__DEFINE__fadapter)

#define MF__DEFINE__adapt(type)                         \
inline auto& adapt(const fraction_data<type>& data)     \
{                                                       \
    static fadapter_##type adapter {data};              \
    return adapter.out;                                 \
}                                                       //
MF__OVERLOAD_DEFAULTS(MF__DEFINE__adapt)
MF__OVERLOAD_RARES(MF__DEFINE__adapt)



#define MF__ASSERT_CXXandC_COMPATIBILITY(type) \
    static_assert(sizeof(fraction_data<type>) == sizeof(MF__(fraction_##type##_t)), "Uncaught Exception: fraction_data<"#type"> != (mf__)fraction_"#type"_t"); \
    static_assert(alignof(fraction_data<type>) == alignof(MF__(fraction_##type##_t)), "Uncaught Exception: fraction_data<"#type"> != (mf__)fraction_"#type"_t"); //
MF__OVERLOAD_DEFAULTS(MF__ASSERT_CXXandC_COMPATIBILITY)
MF__OVERLOAD_RARES(MF__ASSERT_CXXandC_COMPATIBILITY)



#define MF__DEFINE__get_look_of_fraction__CXX(type)                     \
inline auto get_look_of_fraction(const fraction_data<type> & data)      \
    { return MF__(get_look_of_fraction__##type)(adapt(data)); }         //    
MF__OVERLOAD_DEFAULTS(MF__DEFINE__get_look_of_fraction__CXX)
MF__OVERLOAD_RARES(MF__DEFINE__get_look_of_fraction__CXX)



#define MF__DEFINE__stringify_fraction__CXX(type)                   \
inline auto stringify_fraction(const fraction_data<type> data)      \
{                                                                   \
    char* converted = MF__(stringify_fraction__##type)(adapt(data));\
    std::string boxed {converted};                                  \
    delete converted;                                               \
    return boxed;                                                   \
}                                                                   //
MF__OVERLOAD_DEFAULTS(MF__DEFINE__stringify_fraction__CXX)
MF__OVERLOAD_RARES(MF__DEFINE__stringify_fraction__CXX)



#define MF__DEFINE__extract_integer__CXX(type)                  \
inline auto extract_integer(fraction_data<type> & data)         \
    { return MF__(extract_integer__##type)(&adapt(data)); }     //
MF__OVERLOAD_DEFAULTS(MF__DEFINE__extract_integer__CXX)
MF__OVERLOAD_RARES(MF__DEFINE__extract_integer__CXX)



#define MF__DEFINE__extract_fractional__CXX(type)                   \
inline auto extract_fractional(fraction_data<type> & data)          \
    { return MF__(extract_fractional__##type)(&adapt(data)); }      //
MF__OVERLOAD_DEFAULTS(MF__DEFINE__extract_fractional__CXX)
MF__OVERLOAD_RARES(MF__DEFINE__extract_fractional__CXX)



#define MF__DEFINE__multiply_denominator__CXX(type)                     \
template <typename _Ty>                                                 \
inline auto multiply_denominator(fraction_data<type> & data, _Ty mul)   \
    { return MF__(multiply_denominator__##type)(&adapt(data), mul); }   //
MF__OVERLOAD_DEFAULTS(MF__DEFINE__multiply_denominator__CXX)
MF__OVERLOAD_RARES(MF__DEFINE__multiply_denominator__CXX)



#define MF__DEFINE__reduce_fraction__CXX(type)                  \
inline auto reduce_fraction(fraction_data<type> & data)         \
    { return MF__(reduce_fraction__##type)(&adapt(data)); }     //
MF__OVERLOAD_DEFAULTS(MF__DEFINE__reduce_fraction__CXX)
MF__OVERLOAD_RARES(MF__DEFINE__reduce_fraction__CXX)



#define MF__DEFINE__convert_to_same_look__CXX(type)                                 \
inline auto convert_to_same_look(fraction_data<type> & a, fraction_data<type> & b)  \
    { return MF__(convert_to_same_look__##type)(&adapt(a), &adapt(b)); }            //
MF__OVERLOAD_DEFAULTS(MF__DEFINE__convert_to_same_look__CXX)
MF__OVERLOAD_RARES(MF__DEFINE__convert_to_same_look__CXX)



}  //namespace internal
}  //namespace mf
