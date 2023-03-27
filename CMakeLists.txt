cmake_minimum_required(VERSION 3.0)
project(OpenFlexure)

add_subdirectory(src)
add_subdirectory(test)


set_target_properties(OpenFlexure PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../bin/)
set_property(TARGET OpenFlexure PROPERTY AUTOMOC ON)
add_compile_options(-Wall)


enable_testing()

add_test(
    NAME test
    COMMAND ./test/main
)
