cmake_minimum_required(VERSION 3.1)
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED On)
# set(CMAKE_CXX_EXTENSIONS Off)

project(cellUview)

add_subdirectory(src)
add_subdirectory(test)


set_target_properties(cellUview PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../bin/ )
#set_property(TARGET cellUview PROPERTY CXX_STANDARD 17)
#set_property(TARGET cellUview PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET cellUview PROPERTY AUTOMOC ON)
add_compile_options(-Wall)


enable_testing()

add_test(
    NAME test
    COMMAND ./test/main
)
