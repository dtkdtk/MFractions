cmake_minimum_required(VERSION 3.19)
include("./CMakeEnablePedantic.cmake")

set(CoreFiles "include/core/config.h" "include/core/typedefs.h" "include/core/overloads.h" "include/core/lib.h" "include/core/core.h" "include/core/operators.h" "include/fractions.h")
set(CxxBindingFiles "include/rare-overloads.h" "include/cxx-bindings.hpp" "include/fractions.hpp")

project(MyFractions VERSION 1.0 LANGUAGES C)
add_library(MyFractions STATIC ${CoreFiles})
set(COMPILE_OPTIONS "/std:c11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /std:c11")
set_property(TARGET MyFractions PROPERTY C_STANDART 11)
set_target_properties(MyFractions PROPERTIES LINKER_LANGUAGE C)

# CXX addon
project(MyFractionsCXX VERSION 1.0 LANGUAGES C CXX)
set(COMPILE_OPTIONS "/std:c++14 /std:c11")
add_library(MyFractionsCXX STATIC ${CoreFiles} ${CxxBindingFiles})
set(COMPILE_OPTIONS "/std:c11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /std:c11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14")
set_property(TARGET MyFractionsCXX PROPERTY CXX_STANDARD 14 C_STANDART 11)
set_property(TARGET MyFractionsCXX PROPERTY C_STANDART 11)
set_target_properties(MyFractionsCXX PROPERTIES LINKER_LANGUAGE C)

enable_testing()
include("./test/test.c.cmake")
include("./test/test.cpp.cmake")

enable_c_compiler_flag_if_supported("-Wall")
enable_c_compiler_flag_if_supported("-Wextra")
enable_c_compiler_flag_if_supported("-pedantic")
