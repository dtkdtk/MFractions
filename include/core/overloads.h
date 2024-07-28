#pragma once
#include "typedefs.h"



/// Generates overloads for the most common types
/// Warning: the type must not contain spaces.
/// @param generator Any macro with the "type" argument
#define MF__OVERLOAD_DEFAULTS(generator)	\
	generator(i32)							\
	generator(i64)							//



/// Generates overloads for other types (non-common)
/// Warning: the type must not contain spaces.
/// @param generator Any macro with the "type" argument
#define MF__OVERLOAD_RARES(generator)\
	generator(i8)					\
	generator(u8)					\
	generator(i16)					\
	generator(u16)					\
	generator(u32)					\
	generator(u64)					//

/// Generates overloads for types with floating-point
/// Warning: the type must not contain spaces.
/// @param generator Any macro with the "type" argument
#define MF__OVERLOAD_FLOATS(generator)	\
	generator(f32)						\
	generator(f64)						//
