#pragma once
#include "cxx-bindings.hpp"



#define __MAKE_OPERATORS__MATH(type, op, opname)							\
	inline auto operator op (fraction_data<type> & other) const noexcept	\
		{ return MF__(opname##_fractions__##type)(this->d, other); }		//
#define __MAKE_OPERATORS__COMPARISON(type, op, opname)						\
	inline bool operator op (fraction_data<type> & other) const noexcept	\
		{ return MF__(fractions_##opname##__##type)(this->d, other); }		//
#define __MF__OVERLOAD_MATH__CXX(type) __MF__MATH_OPS(__MAKE_OPERATORS__MATH, type)
#define __MF__OVERLOAD_COMPARISON__CXX(type) __MF__COMPARISON_OPS(__MAKE_OPERATORS__COMPARISON, type)



namespace mf
{



template <typename _Ty>
class fraction
{
public:
	fraction_data<_Ty> d;

	inline fraction(_Ty numerator, _Ty denominator, _Ty integer)
	{
		d.numerator = numerator;
		d.denominator = denominator;
		d.integer = integer;
	}
	inline auto get_look() const noexcept
		{ return internal::get_look_of_fraction(d); }
	inline auto to_string() const
		{ return internal::stringify_fraction(d); }
	inline auto extract_integer() noexcept
		{ return internal::extract_integer(d); }
	inline auto extract_fractional() noexcept
		{ return internal::extract_fractional(d); }
	template <typename _Ty>
	inline auto multiply_denominator(_Ty multiplier) noexcept
		{ return internal::multiply_denominator(d, multiplier); }
	inline auto reduce_fraction() noexcept
		{ return internal::reduce_fraction(d); }
	
	MF__OVERLOAD_DEFAULTS(__MF__OVERLOAD_MATH__CXX)
	MF__OVERLOAD_RARES(__MF__OVERLOAD_MATH__CXX)
	MF__OVERLOAD_DEFAULTS(__MF__OVERLOAD_COMPARISON__CXX)
	MF__OVERLOAD_RARES(__MF__OVERLOAD_COMPARISON__CXX)
};

#undef __MF__OVERLOAD_MATH__CXX
#undef __MF__OVERLOAD_COMPARISON__CXX



}  //namespace mf
