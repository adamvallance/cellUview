#SETUP script. Author Adam Vallance. This script installs prerequisite packages. Builds and installs cmake 
#if the version is insufficient, and then builds opencv (image processing) and also builds and installs exiv2 (for image metadata handling) and 

#installs prerequisite packages
getPrerequisites(){
    cwd=$(pwd)
    sudo apt update
    sudo apt upgrade
    pkgs=(gcc cmake build-essential libtool autoconf unzip wget qtbase5-dev qtdeclarative5-dev  libgtest-dev qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools) #dont think these are needed anymore but coudl be: python3 python3-dev glibc-source)
    sudo apt-get -y --ignore-missing install "${pkgs[@]}"

    cd /usr/src/gtest
    sudo cmake CMakeLists.txt
    sudo make
    sudo cp *.a /usr/lib
    cd $cwd

}


installExif(){
    
    #install exiftool
    cwd=$(pwd)
    wget http://exiftool.org/Image-ExifTool-12.58.tar.gz || exit 1
    tar -xf Image-ExifTool-12.58.tar.gz
    rm -rf Image-ExifTool-12.58.tar.gz
    cd Image-ExifTool-12.58
    perl Makefile.PL
    make test
    sudo make install
    cd ..
    rm -rf Image-ExifTool-12.58
    cd src
    wget http://exiftool.org/cpp_exiftool/cpp_exiftool.tar.gz || exit 1
    tar -xf cpp_exiftool.tar.gz
    rm -rf cpp_exiftool.tar.gz
    cd cpp_exiftool
    make
    cp inc/* src/
    cd src
    sudo ar -rc exifLibrary.a *.o
    cd ../.. 
    cd $cwd


    #note that exiftool library is built inside src/cpp rather than a /inc folder for cmake simplicity
}



#https://docs.opencv.org/3.4/d7/d9f/tutorial_linux_install.html

installOpenCV2(){
cwd=$(pwd)    
if [ ! -d "opencv" ]; then
  wget https://github.com/opencv/opencv/archive/refs/tags/4.7.0.tar.gz || exit 1
  tar -xf 4.7.0.tar.gz
  rm -rf 4.7.0.tar.gz
  mv opencv-4.7.0 opencv
  cd opencv
  mkdir build && cd build
  cmake -D CMAKE_BUILD_TYPE=Release 
   -D CMAKE_INSTALL_PREFIX=/usr/local 
  cmake -D BUILD_LIST=improc,videoio ..  
  make -j4 || exit 1
  sudo make install
  cd ../..

fi
cd $cwd

}

installCppFlow(){
    cwd=$(pwd)  
    #get tensorflow 2 C API
    file="libtensorflow-gpu-linux-x86_64-2.11.0.tar.gz"
    wget https://storage.googleapis.com/tensorflow/libtensorflow/$file || exit 1
    sudo tar -C /usr/local -xzf $file
    sudo ldconfig
    rm $file

    #get cppflow
    git clone https://github.com/serizba/cppflow
    cd cppflow
    mkdir build
    cd build
    cmake ..
    make -j4
    make install
    cd ..
    rm -rf build
    cd $cwd

}

# #main, calls functions already defined
installCppFlow
# getPrerequisites
# installExif
# if [ $# -ne 0 ]; then
#     if [ $1 == '-n' ]; then
#         echo "Skipping opencv installation"
#         exit
#     fi
# fi
# installOpenCV2 





####------DEPRECATED, for higher cmake versions------#####
# #if cmake version less than 3.11 then build from source
# checkCMAKE(){
#     cmakeVerOutput=$(cmake --version)
#     cmakeVer=$(echo $cmakeVerOutput | cut -d' ' -f 3)
#     cmakeMajor=$(echo $cmakeVer | cut -d'.' -f 1)
#     cmakeMinor=$(echo $cmakeVer | cut -d'.' -f 2) 
#     if [ $cmakeMajor -lt 3 ]
#     then

#         installCMAKE3_12
#         return
#     fi
#     if [ $cmakeMajor -eq 3 ]
#     then
#         if [ $cmakeMinor -lt 12 ]
#         then
#             installCMAKE3_12
#             return
#         fi
#     fi
#     echo "CMake $cmakeVer is valid"

# }

# #builds cmake 3.12 from source and installs
# installCMAKE3_12(){
    # echo "Current CMake Version not sufficient. Building and installing cmake 3.12"
    # #save current working directory to return upon completion   
    # cwd=$(pwd)

    # mkdir ~/temp && cd ~/temp
    # wget cmake.org/files/v3.12/cmake-3.12.3.tar.gz
    # tar -xzvf cmake-3.12.3.tar.gz
    # cd cmake-3.12.3/
    # ./bootstrap
    # make -j$(nproc)
    # sudo make install
    # rm -rf temp
    # echo "note that new cmake version will not be recognised until new vscode terminal is started"
    # cd $cwd

# }