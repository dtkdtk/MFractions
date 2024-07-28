add_executable(CoreTest ${CoreFiles} "./test/test.c")
set(COMPILE_OPTIONS "/std:c11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /std:c11")
set_property(TARGET CoreTest PROPERTY C_STANDART 11)
set_target_properties(CoreTest PROPERTIES LINKER_LANGUAGE C)

add_test(NAME CoreTest COMMAND CoreTest)
