
Help()
{
   # Display Help
   echo "Build script help"
   echo
   echo "Syntax: build.sh [-h|r|i|c]"
   echo "options:"
   echo "-h     Print this Help."
   echo "-r     Build and run."
   echo "-i     Build and install executeable onto path /usr/bin. Requires sudo."
   echo "-t     Build and run tests."
   echo "-g     Rebuilds the GUI (copy gui.ui into root directory)."
   echo "-c     Clear CMake Cache and build."
   echo
}

#this function takes a gui.ui file from QT creator copied into the main directory and compiles into the header to be integrated into the main code.

rebuildGUI(){
    cd src/QT
    cp ../../gui.ui . 
    if [ $? -ne 0 ]; then
        echo "ERROR. please copy gui.ui into the main directory"
        exit 1
    fi
    uic gui.ui > qtWindow.h
    if [ $? -ne 0 ]; then
        echo "Error. please ensure that gui.ui is a valid .ui file from QT creator."
        exit 1
    fi
    cd ../..
    rm gui.ui
    echo "Sucessfully rebuilt GUI."

}


##compiles cellUview with CMake
doCmake(){
    if [ $built -eq 0 ]; then
        if [ $clear_cache -eq 1 ]; then
            rm CMakeCache.txt
            echo "CMakeCache cleared."
        fi

        echo "Beginnng cellUviewPlus build"

        if [ $buildGUI -eq 1 ]; then
            rebuildGUI
        fi


        cmake .
        if [ $? -ne 0 ]; then
            echo "Error. Make sure you have the opencv_src and opencv_build in main directory"
            exit
        fi
        make
        if [ $? -ne 0 ]; then
            exit
        fi

        if [ $do_test -eq 1 ]; then
            ./test/main
            echo "Running unit tests..."
            if [ $? -ne 0 ]; then
                echo "Error. Tests failed."
                exit
            fi
        fi

        echo "cellUview build succesful"
        built=1
    fi

}



# #main, handles options from command line
built=0 
installed=0
doRun=0
clear_cache=0
do_test=0
buildGUI=0
#iterates over provided arguments to see if cmake cache being removed. Priority option
for arg in "$@"
do  

   if [ $arg == "-c" ]; then
    clear_cache=1
   fi
   if [ $arg == "-t" ]; then
    do_test=1
   fi
   if [ $arg == "-g" ]; then
    buildGUI=1
   fi
done 

#iterate over again to handle other options
for arg in "$@"
do
     case $arg in
      -h) # display Help
         Help
         exit;;
      -i)
        doCmake
        sudo cp bin/cellUview /usr/bin/ 
        if [ $? -ne 0 ]; then
            echo "Error. Sudo required to install on path. Try without -i option."
            exit 1
        fi
        echo "To run, type cellUview into the terminal"
        installed=1
        ;;
      -r)
        doCmake
        doRun=1
        ;;
       -c) #continue
       ;;
       -t)
       ;;
       -g)
       ;;
     *) # Invalid option
         echo "Error: Invalid option $arg"
         Help
         exit;;
   esac
done 

#build if not already built - no options provided
doCmake 
#if r is input then run either the binary from the default bin/cellUview or from the installed path /usr/bin
if [ $doRun -eq 1 ]; then
    if [ $installed -eq 1 ]; then
        cellUview
        exit
    fi
    if [ $installed -eq 0 ]; then
        bin/cellUview
    fi
fi

