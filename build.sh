
Help()
{
   # Display Help
   echo "Build script help"
   echo
   echo "Syntax: build.sh [-h|i|r]"
   echo "options:"
   echo "h     Print this Help."
   echo "i     Build and install executeable onto path /usr/bin. Requires sudo."
   echo "r     Build and run"
   echo
}


##compiles OpenFlexure with CMake
doCmake(){
    echo "Beginnng OpenFlexurePlus build"
    cmake .
    if [ $? -ne 0 ]; then
        echo "Error. Make sure you have the opencv_src and opencv_build in main directory"
    fi
    make
    if [ $? -ne 0 ]; then
        return
    fi
    echo "OpenFlexure build succesful"

}

#main, handles options from command line
while getopts ":hir" option; do
   case $option in
      h) # display Help
         Help
         exit;;
      i)
        doCmake
        sudo cp bin/OpenFlexure /usr/bin/
        echo "To run, type OpenFlexure into the terminal"
        exit;;
      r)
        doCmake
        bin/OpenFlexure
        exit;;
     \?) # Invalid option
         echo "Error: Invalid option"
         Help
         exit;;
   esac
done


