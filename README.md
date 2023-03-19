# OpenFlexure-microscopy-enhancement
This project provides real-time image processing capabilities for the Raspberry Pi based OpenFlexure microscope platform for image enhancement including contrast and sharpness adjustment, edge detection/enhancement, and classification using k-means clustering.

<img src="https://openflexure.org/assets/ofm-photos/v7_side_view_crop.jpg" width="200" />


# dev instructions
## build openflexureplus
to build, go to main directory and in a terminal type 
```
bash build.sh
```
Then to run enter
```
bin/OpenFlexure
```

```build.sh``` has options:
```
Syntax: build.sh [-h|r|i|c]"
   options:"
   -h     Print this Help."
   -r     Build and run."
   -i     Build and install executeable onto path /usr/bin. Requires sudo."
   -c     Clear CMake Cache and build."
```

Example: If you want to build and run straight away enter:
```
bash build.sh -r 
```
or to build, remove the cmake cache, install and run straight away:
```
bash build.sh -r -c -i
```
If the -i option is used, OpenFlexurePlus can be executed from anywhere by typing 
```
OpenFlexure
```

### Note
Make sure you have opencv_build and opencv_src inside the main directory. install instructions or script to come. 

## Google Test
It is necessary to also install Google Test, as unit tests are run when building.
To install, run the following commands:
```
sudo apt-get install libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib
```
These commands to be added to setup script.

## GUI build
To update the GUI, copy ONLY the gui.ui file generated in QTCreator into  main directory.
Then in a terminal enter
```
bash rebuildGUI.sh
```
before building the whole program as described above.
Edits to connections and signals should be made inside src/gui.cpp