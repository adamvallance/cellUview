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

#adding exif library
#find_library(EXIF_LIB exifLibrary)
add_library(exifLibrary SHARED IMPORTED)
set_target_properties(exifLibrary PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/cpp_exiftool/src/exifLibrary.a)


#compile and link OpenFlexure executable
add_executable(OpenFlexure main.cpp camera.cpp gui.cpp edgeDetection.cpp gallery.cpp erosion.cpp dilation.cpp frame.cpp grayScale.cpp contrastEnhancement.cpp)
#set_property(TARGET OpenFlexure PROPERTY CXX_STANDARD 17)
target_link_libraries(OpenFlexure ${OpenCV_LIBS} Qt5::Widgets Threads::Threads exifLibrary)


#create libraries for testing

add_library(camera camera.cpp camera.h frame.cpp)
target_link_libraries(camera ${OpenCV_LIBS} Threads::Threads)


add_library(imageProc edgeDetection.cpp erosion.cpp dilation.cpp frame.cpp imageProcessor.h grayScale.cpp contrastEnhancement.cpp)
target_link_libraries(imageProc ${OpenCV_LIBS} Threads::Threads)

add_library(gallery gallery.cpp)
target_link_libraries(gallery ${OpenCV_LIBS} exifLibrary Threads::Threads)