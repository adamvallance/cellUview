# OpenFlexure-microscopy-enhancement
This project provides real-time image processing capabilities for the Raspberry Pi based OpenFlexure microscope platform for image enhancement including contrast and sharpness adjustment, edge detection/enhancement, and classification using k-means clustering.

<img src="https://openflexure.org/assets/ofm-photos/v7_side_view_crop.jpg" width="200" />


# dev instructions
## build openflexureplus
to build, go to main directory and in a terminal type
```
cmake . 
make
 ```

to run, 

``` 
bin/OpenFlexure
```

make sure you have opencv_build and opencv_src inside the main directory. install instructions or script to come. 

## GUI build
To update the GUI, copy ONLY the gui.ui file generated in QTCreator into  main directory.
Then in a terminal enter
```
bash rebuildGUI.sh
```
before building the whole program as described above.
Edits to connections and signals should be made inside src/gui.cpp