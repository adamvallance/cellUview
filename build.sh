
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
   echo "-c     Clear CMake Cache and build."
   echo
}


##compiles OpenFlexure with CMake
doCmake(){
    if [ $built -eq 0 ]; then
        if [ $clear_cache -eq 1 ]; then
            rm CMakeCache.txt
            echo "CMakeCache cleared."
        fi

        echo "Beginnng OpenFlexurePlus build"
        cmake .
        if [ $? -ne 0 ]; then
            echo "Error. Make sure you have the opencv_src and opencv_build in main directory"
            exit
        fi
        make
        if [ $? -ne 0 ]; then
            return
            exit
        fi
        echo "OpenFlexure build succesful"
        built=1
    fi

}

# #main, handles options from command line

built=0 
installed=0
doRun=0
clear_cache=0
#iterates over provided arguments to see if cmake cache being removed. Priority option
for arg in "$@"
do  

   if [ $arg == "-c" ]; then
    clear_cache=1
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
        sudo cp bin/OpenFlexure /usr/bin/ 
        if [ $? -ne 0 ]; then
            echo "Error. Sudo required to install on path. Try without -i option."
            exit 1
        fi
        echo "To run, type OpenFlexure into the terminal"
        installed=1
        ;;
      -r)
        doCmake
        doRun=1
        ;;
       -c) #continue
       ;;
     *) # Invalid option
         echo "Error: Invalid option $arg"
         Help
         exit;;
   esac
done 

#build if not already built - no options provided
doCmake 
#if r is input then run either the binary from the default bin/OpenFlexure or from the installed path /usr/bin
if [ $doRun -eq 1 ]; then
    if [ $installed -eq 1 ]; then
        OpenFlexure
        exit
    fi
    if [ $installed -eq 0 ]; then
        bin/OpenFlexure
    fi
fi

