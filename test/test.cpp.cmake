add_executable(CxxBindingsTest ${CoreFiles} ${CxxBindingFiles} "./test/test.cpp")
set(COMPILE_OPTIONS "/std:c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14")
set_property(TARGET CxxBindingsTest PROPERTY CXX_STANDART 14)
set_target_properties(CxxBindingsTest PROPERTIES LINKER_LANGUAGE CXX)

add_test(NAME CxxBindingsTest COMMAND CxxBindingsTest)
