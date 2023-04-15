
# cellUview-microscopy-enhancement

[![CMake](https://github.com/adamvallance/openflexure-microscopy-enhancement/actions/workflows/cmake.yml/badge.svg)](https://github.com/adamvallance/openflexure-microscopy-enhancement/actions/workflows/cmake.yml)

This project provides real-time image processing capabilities for the Raspberry Pi based cellUview microscope platform for image enhancement including contrast and sharpness adjustment, edge detection/enhancement, and classification using k-means clustering.

<img src="https://openflexure.org/assets/ofm-photos/v7_side_view_crop.jpg" width="200" />

# dev instructions
To get cellUview+, go to a terminal and type
```
git clone https://github.com/adamvallance/openflexure-microscopy-enhancement.git
cd openflexure-microscopy-enhancement
sudo bash setup.sh
```
Alternatively, to avoid rebuilding opencv 4.7.0, if already installed on machine enter
```
sudo bash setup.sh -n
```


## build openflexureplus
to build, go to main directory and in a terminal type 
```
bash build.sh
```
Then to run enter
```
bin/cellUview
```

```build.sh``` has options:
```
Syntax: build.sh [-h|r|i|c]
   options:
   -h     Print this Help.
   -r     Build and run.
   -i     Build and install executeable onto path /usr/bin. Requires sudo.
   -t     Build and run tests.
   -c     Clear CMake Cache and build.
```

Example: If you want to build and run straight away enter:
```
bash build.sh -r 
```
or to build, remove the cmake cache, install and run straight away:
```
bash build.sh -r -c -i
```
If the -i option is used, cellUviewPlus can be executed from anywhere by typing 
```
cellUview
```

### Note
Make sure you have opencv_build and opencv_src inside the main directory. install instructions or script to come. 

## Google Test

<!-- ### Installation
It is necessary to also install Google Test, as unit tests are run when building.
To install, run the following commands:
```
sudo apt-get install libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib
```
These commands to be added to setup script. -->

### Adding Tests

Unit tests should be written for new classes. The existing test files (```gtest_camera.h``` and ```gtest_edgedetect.h```) in the test folder can be used as examples of how tests can be implemented.

Tests are written inside test functions which take the form:
```
TEST(testSuiteName, testName){
   //test in here
}
```
There can be multiple different test functions within a test header file. These likely will belong to the same test suite but each have distinct test names. 

The actual checks carried out within the tests are called "assertions" and take two general forms: ```EXPECT``` which generate non-fatal failures, and ```ASSERT``` which generate fatal failures. For instance, the assertion
```
EXPECT_EQ(variable1, variable2)
```
can be used to check that two variables are equal as expected, and generates a non-fatal failure if untrue. Other possible assertions can be found in the Google Test documentation.

This gtest header file should include ```<gtest/gtest.h>``` as well as the header of the class under test. If testing an element of the callback chain structure, an "end tester" tool ```gtest_endtest.h``` has been written to get the returned output frame. An example implementation of this can be found in ```gtest_edgedetect.h```.

Once a test has been written, there are several more steps to get it integrated into the unit test framework. If it has not already been done, a library for the class being tested must be added to the ```CMakeLists.txt``` file in src. An example of this for the ```camera``` class is shown below.
```
add_library(camera camera.cpp camera.h)
target_link_libraries(camera ${OpenCV_LIBS} Threads::Threads)
```
Next, the ```target_link_libraries()``` line in ```test/CMakeLists.txt``` should be updated to append the newly created library in ```src/CMakeLists.txt``` to the end of the list. 

Finally, ```main.cpp``` in test should be updated to include the new test header file.

To run the tests, re-run ```build.sh``` as the unit tests are automatically run during building.

## GUI build
To update the GUI, copy ONLY the gui.ui file generated in QTCreator into  main directory and run the build script with option -g.
```
bash build.sh -g
```
Edits to connections and signals should be made inside src/gui.cpp

## Documentation

Add docstrings above classes and methods like follows:
```
/** 
* Here is a doxygen comment.
**/
class Example Class{
```

There are also keywords like ```@returns``` to explain what a function returns for example. Gets formatted nicely by doxygen. Refer to the doxygen guide for more stuff like this.

To update the docs, run ```doxygen``` in main repo directory. Doxygen install is added to the setup script. Maybe we can automate this process on pull request?

To view the online docs, nagivate to ```/docs/html``` and open ```index.html```. Next step to add this to a github pages link.
