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

It is recommended to use a Raspberry Pi 4B for OpenFlexure. In order to use cellUview, we advise using a clean install of Raspbian v10 (Buster), rather than the supplied Raspbian OpenFlexure OS. 

cellUview, just like OpenFlexure, supports motor control built on the open-source SangaBoard motor controller. However, any custom Arduino-based motor controller board that can use the SangaBoard firmware is supported. Instructions on how to build your own custom SangaBoard- and OpenFlexure-compatible motor board can be found <a href="https://build.openflexure.org/openflexure-microscope/test-gitbuilding/motor_controllers.html">here</a>. If using a custom board, please ensure this is flashed with the SangaBoard firmware,  <a href="https://gitlab.com/bath_open_instrumentation_group/sangaboard/tree/master/arduino_code">available here</a>.

<div align="center">
<img src="https://github.com/adamvallance/cellUview/blob/main/images/ezgif-2-f8974a17cf.gif" alt="openflexure microscope, source: https://www.youtube.com/watch?v=IqjsVWdwYfg" width="600"/>
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


# Using cellUview

cellUview has an easy-to-use UI to make real-time microscopy image sample processing simple, even for novice users. The interface, shown in the guide videos below, is split into different sections. In the centre is the microscope video stream showing which updates in real-time to show all of your applied image processing settings - which can be controlled in the panel directly below the stream. In the upper right hand corner is the motor control panel, and on the left hand side are the capture controls and image gallery. 

<!-- k-means analysis right bottom? -->

In the motor control panel you can view and control the position of the OpenFlexure motors for x, y, and z axes, either by typing in the desired position or using the buttons to step the motors. Controls for the x- and y-axis will move the microscope slide laterally, whereas z-axis control can be used to focus the image correctly. If the motors are not connected, for instance if cellUview is being used on an earlier version of OpenFlexure with manual control only, then this panel is disabled.

https://user-images.githubusercontent.com/72609606/232557070-711c9b05-bb8e-4470-a1ea-78805089fca2.mp4

With the sample now in focus, it's time to apply the image processing algorithms to help with analysis. Processing settings are changed with the labelled sliders and toggle buttons.

https://user-images.githubusercontent.com/72609606/232560502-6fe65015-7f32-4afa-8bab-2b32e7a25eb7.mp4

When the image settings are to your liking, a capture can be taken with a brief description. This will then be shown in the gallery on the left hand side.

https://user-images.githubusercontent.com/72609606/232560614-edb1f39d-e222-45b4-99c6-45c785a1bc81.mp4

Any of the images in the gallery can be selected to show them at full size in a separate window. The captured images also store their processing settings which can be reapplied to the current stream with just a click for convenient repeatability.

https://user-images.githubusercontent.com/72609606/232560682-0aba59dd-6694-4a25-9400-9e8d12413d23.mp4


# Follow us on social media

Keep up to date on project development by starring this GitHub and following us on social media:

<p align="center">
<a href="https://twitter.com/cellUview" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="signups" height="150" width="100" /></a>
<a href="https://www.tiktok.com/@cell_u_view" target="blank"><img align="center" src="https://upload.wikimedia.org/wikipedia/en/a/a9/TikTok_logo.svg" alt="tiktok" height="150" width="150" /></a> ·
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

This code is distributed under the GNU GPL-3.0 license. See [`LICENSE`](https://github.com/adamvallance/cellUview/blob/main/LICENSE) for more details.


# Contributors

This is a project being carried out by a group of University of Glasgow engineering students. Please feel free to get in touch with any of us if you have questions about the project.
* <a href="https://github.com/adamvallance">Adam Vallance</a>
* <a href="https://github.com/Mark-Main">Mark Main</a>
* <a href="https://github.com/mlsalloum">Malik Salloum</a>
* <a href="https://github.com/n0ob1243">Jake Beveridge</a>


# Credits

Credits to Richard Bowman and the <a href="https://openflexure.org/">OpenFlexure microscope platform</a> that this project was built upon.

Credits to Bernd Porr's <a href="https://github.com/berndporr/opencv-camera-callback">OpenCV Camera Callback Class</a>, and Phil Harvey's <a href="https://exiftool.org/">C++ ExifTool library</a> for reading and writing metadata.

