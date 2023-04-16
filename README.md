# cellUview

<br />
<div align="center">
 <img src="https://github.com/adamvallance/cellUview/blob/main/images/cellUview_logo_big.png?raw=true" alt="logo" width="300" div al ign=center />
 <br />
 A real-time image processing suite for digital microscopy.

 </br>
 <br />

[![CMake](https://github.com/adamvallance/openflexure-microscopy-enhancement/actions/workflows/cmake.yml/badge.svg)](https://github.com/adamvallance/openflexure-microscopy-enhancement/actions/workflows/cmake.yml)
![Docs](https://github.com/adamvallance/cellUview/actions/workflows/docs.yml/badge.svg)
<br />
    <a href="https://github.com/adamvallance/cellUview/issues">Report a Bug or Request a Feature</a>
<br />

</div>
<h3 align="left"></h3>


# Summary

cellUview provides a real-time image processing suite designed for the open-source, Raspberry Pi based OpenFlexure microscope platform - with capabilities such as contrast and exposure adjustment, erosion and dilation, flat field correction, edge detection/enhancement, and classification using k-means clustering. It also allows for easy image capturing with an in-build gallery viewer, and a quick, simple way to restore processing settings from a previous capture.


# Getting Started

## Hardware

cellUview is designed for the Raspberry Pi based OpenFlexure microscope, an open-source 3D printed microscope platform (pictured below). More information, including full manufacturing and assembly instructions as well as the required STL files can be found on the <a href="https://openflexure.org/">OpenFlexure website</a>. 

cellUview, just like OpenFlexure, supports motor control built on the open-source SangaBoard motor controller. However, any custom Arduino-based motor controller board that can use the SangaBoard firmware is supported. Instructions on how to build your own custom SangaBoard- and OpenFlexure-compatible motor board can be found <a href="https://build.openflexure.org/openflexure-microscope/test-gitbuilding/motor_controllers.html">here</a>. If using a custom board, please ensure this is flashed with the SangaBoard firmware,  <a href="https://gitlab.com/bath_open_instrumentation_group/sangaboard/tree/master/arduino_code">available here</a>.

<div align="center">
<img src="https://openflexure.org/assets/ofm-photos/v7_side_view_crop.jpg" alt="openflexure microscope" width="200"/>
</div>

## Installing the Software

**Please note:** this project is designed for Raspberry Pi systems, and as such is not guaranteed to build on all Linux distros. In particular the WiringPi library, which is installed by default on Raspbian systems, does not have releases on all platforms.

The following procedure also requires ```git```, which can be installed by typing ```sudo apt install git``` in a terminal if it has not already been installed.

The installation process for cellUview is simple. 

**In a terminal, first clone this GitHub and enter the project directory by typing:**
```
git clone https://github.com/adamvallance/cellUview.git
cd cellUview
```
**Then run the setup script with:**
```
sudo bash setup.sh
```
This will install all the libraries required to run cellUview. This process can take some time, up to around 10-15 minutes to build all the dependencies. Alternatively, to speed up the process if OpenCV 4.7.0 is already installed on the system, this part of the setup can be skipped with:
```
sudo bash setup.sh -n
```

**Next, build cellUview by running:**
```
bash build.sh
```
And that's it, cellUview is now ready for use.

```build.sh``` also has some additional options:
```
Syntax: build.sh [-h|r|i|c]
   options:
   -h     Print this Help.
   -r     Build and run.
   -i     Build and install executeable onto path /usr/bin. Requires sudo.
   -t     Build and run tests.
   -c     Clear CMake Cache and build.
```
For instance, if you want to build and run the program straight away, type:
```
bash build.sh -r 
```
Or, to build, remove the cmake cache, and install the program onto the system:
```
bash build.sh -c -i
```

**To launch cellUview, run the executable in the ```/bin/``` directory by typing:**
```
bin/cellUview
```
Or, if the ```-i``` option was used when building, cellUview can be run from anywhere by simply typing 
```
cellUview
```


# Follow us on social media

Keep up to date on project development by starring this GitHub and following us on social media:

<p align="center">
<a href="https://twitter.com/cellUview" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="signups" height="150" width="100" /></a>
<a href="https://www.tiktok.com/@celluview" target="blank"><img align="center" src="https://upload.wikimedia.org/wikipedia/en/a/a9/TikTok_logo.svg" alt="tiktok" height="150" width="150" /></a> ·
<a href="https://www.instagram.com/cellUview" target="blank"><img align="center" src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/e7/Instagram_logo_2016.svg/1024px-Instagram_logo_2016.svg.png" alt="instagram" height="100" width="100" /></a> 
</p>


# Documentation

Documentation for cellUview can be viewed <a href="https://adamvallance.github.io/cellUview/annotated.html">here</a>.

These documents are generated using Doxygen, using the docstrings added throughout the code. Documentation is kept up-to-date automatically through the GitHub continuous integration action '<a href="https://github.com/adamvallance/cellUview/actions/workflows/docs.yml">Docs</a>'.


# Unit Tests

Unit tests, using the Google Test framework, have been written for cellUview. Google Test system dependencies are installed with the cellUview ```setup.sh``` script. As mentioned in the **Installing the Software** section, unit tests can be run by using the ```-t``` option in the build script, i.e. by running:
```
bash build.sh -t
```
inside the cellUview project directory.

These tests are also run as a part of the GitHub continuous integration action '<a href="https://github.com/adamvallance/cellUview/actions/workflows/cmake.yml">CMake</a>'.


# License 

TBD


# Contributors

This is a project being carried out by a group of University of Glasgow engineering students. Please feel free to get in touch with any of us if you have questions about the project.
* <a href="https://github.com/adamvallance">Adam Vallance</a>
* <a href="https://github.com/Mark-Main">Mark Main</a>
* <a href="https://github.com/mlsalloum">Malik Salloum</a>
* <a href="https://github.com/n0ob1243">Jake Beveridge</a>


# Credits

Credits to Bernd Porr's <a href="https://github.com/berndporr/opencv-camera-callback">OpenCV Camera Callback Class</a>, and Phil Harvey's <a href="https://exiftool.org/">C++ ExifTool library</a> for reading and writing metadata.




# OLD DEV STUFF
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
