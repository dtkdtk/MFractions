# MFractions
Tiny C library for basic math calculations with fractions

> [!WARNING]\
> At the moment, MFractions is tested only on Windows 10 and MVSC compiler. If you have issues with compiling on other platforms - please create [a pull request (PR)](https://github.com/dtkdtk/MFractions/pulls) or [an issue](https://github.com/dtkdtk/MFractions/issues) in the GitHub repository.

# Features
- Built-in C++ bindings
- Support for all numeric data types (by C overloading mechanism)
- Math & comparison operators
- Optional C namespacing (e.g. `mf__reduce_fraction__i32()`)

# TODO
- [ ] Documentation
- [ ] 100% compatibility with Linux & MacOS
- [ ] More functions for math calculations with fractions
- [ ] Bindings for other languages:
	- [ ] JavaScript
	- [ ] Rust
	- [ ] Python
	- [ ] Java
	- [ ] C#

# About the C code-generation (overloading mechanism)
All functions (and also the `fraction_<*>_t` structure) are wrapped in the same-named macros - `MF__DEFINE__<name>`, which accept the `type` argument - i.e. any numeric data type. These macros are **generators**. They generate a **function overload** for the specified data type.
> [!NOTE]\
> We recommend you to use [our typedefs](https://github.com/dtkdtk/MFractions/blob/master/include/core/typedefs.h), because they are easy-to-read as part of the function name and they are short (compare `mf__convert_to_same_look__unsigned_long_long` with `mf__convert_to_same_look__u64`) and **they do not contain spaces**.
As mentioned above (and in each comment above any generator), `type` must not contain spaces. Spaces cause syntax errors (e.g. `inline void mf__do_sth_unsigned int (...) {...}`).

If you need to overload a specific function for a specific data type, try manually overloading the function by adding this code immediately after including the headers:
```c
/* #include ... */

MF__DEFINE__fraction_struct( <type> ) //don't forget to overload the fraction type!!!
MF__DEFINE__<fn_name>( <type> )
```
...where `<type>` is your data type, and `<fn_name>` is the target function name.
Example: (needed overload of the `reduce_fraction` function for type `u16`)
```c
/* #include ... */

MF__DEFINE__fraction_struct(u16)
mf__DEFINE__reduce_fraction(u16)
```

# API
TODO
