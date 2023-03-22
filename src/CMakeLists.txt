set(CMAKE_AUTOMOC ON)

#opencv
set(OpenCV_DIR "../opencv_build")
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

#qt
find_package(Qt5Widgets REQUIRED)

#threads
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

#compile and link OpenFlexure executable
add_executable(OpenFlexure main.cpp camera.cpp gui.cpp processingTemplate.cpp edgeDetection.cpp gallery.cpp)
target_link_libraries(OpenFlexure ${OpenCV_LIBS} Qt5::Widgets Threads::Threads)


#create libraries for testing

add_library(camera camera.cpp camera.h)
target_link_libraries(camera ${OpenCV_LIBS} Threads::Threads)

add_library(edgeDetection edgeDetection.cpp edgeDetection.h)
target_link_libraries(edgeDetection ${OpenCV_LIBS} Threads::Threads)
