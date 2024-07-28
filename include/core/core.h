#pragma once
#include "config.h"
#include "lib.h"
#include "overloads.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif



enum MF__(fraction_look_types_e)
{
	MF__(proper_fraction),
	MF__(improper_fraction),
	MF__(mixed_fraction),
	MF__(integer_fraction)
};



/// Warning: 'type' param should not contain spaces
#define MF__DEFINE__fraction_struct(type)		\
typedef struct MF__(fraction_##type##_t)		\
{												\
	type numerator;								\
	type denominator;							\
	type integer;								\
} MF__(fraction_##type##_t);					//
MF__OVERLOAD_DEFAULTS(MF__DEFINE__fraction_struct)



/// Warning: 'type' param should not contain spaces
#define MF__DEFINE__alloc_fraction(type)								\
inline MF__(fraction_##type##_t*) MF__(alloc_fraction__##type)(void)	\
{																		\
	MF__(fraction_##type##_t) * data = (MF__(fraction_##type##_t*))		\
		malloc(sizeof(MF__(fraction_##type##_t)));						\
	MF__ASSERT_PTR_NONNULL(data)										\
	memset(data, 0, sizeof(MF__(fraction_##type##_t)));					\
	return data;														\
}																		//
MF__OVERLOAD_DEFAULTS(MF__DEFINE__alloc_fraction)



/// Warning: 'type' param should not contain spaces	
#define MF__DEFINE__get_look_of_fraction(type)			\
inline enum MF__(fraction_look_types_e) MF__(get_look_of_fraction__##type)(const MF__(fraction_##type##_t) data)\
{														\
	if (data.integer > 0 && data.numerator == 0)		\
		return MF__(integer_fraction);					\
	if (data.integer > 0 && data.numerator > 0)			\
		return MF__(mixed_fraction);					\
	if (data.numerator < data.denominator)				\
		return MF__(proper_fraction);					\
	else												\
		return MF__(improper_fraction);					\
}														//
/// Gets the type of fraction (proper, improper, or mixed)
MF__OVERLOAD_DEFAULTS(MF__DEFINE__get_look_of_fraction)



/// Warning: Possibility of buffer overflow
/// Warning: 'type' param should not contain spaces
#define MF__DEFINE__stringify_fraction(type)				\
char* MF__(stringify_fraction__##type)(const MF__(fraction_##type##_t) data)\
{															\
	char* buffer = (char*)malloc(64 * sizeof(char));		\
	MF__ASSERT_PTR_NONNULL(buffer)							\
	memset((void*)buffer, 0, 64 * sizeof(char));			\
	char number_buffer[24] = "";							\
	_i64toa_s(data.integer, number_buffer, 10, 10);			\
	strcat(buffer, number_buffer);							\
	strcat(buffer, "+(");									\
	_i64toa_s(data.numerator, number_buffer, 10, 10);		\
	strcat(buffer, number_buffer);							\
	strcat(buffer, "/");									\
	_i64toa_s(data.denominator, number_buffer, 10, 10);		\
	strcat(buffer, number_buffer);							\
	strcat(buffer, ")");									\
	return buffer;											\
}															//
/// Converts a fraction into a string
MF__OVERLOAD_DEFAULTS(MF__DEFINE__stringify_fraction)



/// Warning: 'type' param should not contain spaces
#define MF__DEFINE__extract_integer(type)					\
inline void MF__(extract_integer__##type)(MF__(fraction_##type##_t) * data)\
{															\
	type integer = data->numerator / data->denominator;		\
	if (integer == 0) return;								\
	data->integer += integer;								\
	data->numerator -= integer * data->denominator;			\
}															//
/// Converts an improper (mixed) fraction into a proper fraction
/// Warning: Has side effects
MF__OVERLOAD_DEFAULTS(MF__DEFINE__extract_integer)



/// Converts a mixed (improper) fraction into an improper fraction
/// Warning: 'type' param should not contain spaces
#define MF__DEFINE__extract_fractional(type)					\
inline void MF__(extract_fractional__##type)(MF__(fraction_##type##_t) * data)\
{																\
	if (data->integer == 0) return;								\
	data->numerator += data->integer * data->denominator;		\
	data->integer = 0;											\
}																//
/// The opposite of extract_integer
/// Warning: Has side effects
MF__OVERLOAD_DEFAULTS(MF__DEFINE__extract_fractional)



/// Warning: 'type' param should not contain spaces
#define MF__DEFINE__multiply_denominator(type)										\
inline void MF__(multiply_denominator__##type)(MF__(fraction_##type##_t) * data,	\
											  type multiplier)						\
{																					\
	MF__(extract_fractional__##type)(data);											\
	data->denominator *= multiplier;												\
	data->numerator *= multiplier;													\
}																					//
/// Multiplies the numerator and denominator by a specific number
/// Implicitly makes the fraction improper
/// Warning: Has side effects
/// Warning: Possibility of variable overflow
MF__OVERLOAD_DEFAULTS(MF__DEFINE__multiply_denominator)



/// Warning: 'type' param should not contain spaces
#define MF__DEFINE__reduce_fraction(type)								\
inline bool MF__(reduce_fraction__##type)(MF__(fraction_##type##_t) * data)\
{																		\
	type gcd = MF__(GCD__##type)(data->numerator, data->denominator);	\
	if (gcd == 1) return false;											\
	data->numerator /= gcd;												\
	data->denominator /= gcd;											\
	return true;														\
}																		//
/// Divides the numerator and denominator of a fraction by GCD
/// Warning: Has side effects
MF__OVERLOAD_DEFAULTS(MF__DEFINE__reduce_fraction)



/// Warning: 'type' param should not contain spaces
#define MF__DEFINE__convert_to_same_look(type)									\
inline void MF__(convert_to_same_look__##type)(MF__(fraction_##type##_t) * a,	\
											   MF__(fraction_##type##_t) * b)	\
{																				\
	MF__(extract_fractional__##type)(a);										\
	MF__(extract_fractional__##type)(b);										\
	MF__(reduce_fraction__##type)(a);											\
	MF__(reduce_fraction__##type)(b);											\
	type lcm = MF__(LCM__##type)(a->denominator, b->denominator);				\
	MF__(multiply_denominator__##type)(a, lcm / a->denominator);				\
	MF__(multiply_denominator__##type)(b, lcm / b->denominator);				\
}																				//
/// Extracts the fractional part and reduces fractions to a common denominator
/// Warning: Has side effects
MF__OVERLOAD_DEFAULTS(MF__DEFINE__convert_to_same_look)



#ifdef __cplusplus
}  //extern "C"
#endif
