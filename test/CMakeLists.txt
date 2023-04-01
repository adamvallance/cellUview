cmake_minimum_required(VERSION 3.0)
project(OpenFlexure)

set(OpenCV_DIR "../opencv_build")

find_package(OpenCV REQUIRED)
find_package(GTest REQUIRED)

include_directories(../src)

enable_testing()

add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS} gtest gtest_main camera edgeDetection imageProc)


