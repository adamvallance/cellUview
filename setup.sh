#SETUP script. Author Adam Vallance. This script installs prerequisite packages. Builds and installs cmake 
#if the version is insufficient, and then builds opencv (image processing) and also builds and installs exiv2 (for image metadata handling) and 

#installs prerequisite packages
getPrerequisites(){
    sudo apt update
    sudo apt upgrade
    pkgs=(gcc cmake build-essential libtool autoconf unzip wget qtbase5-dev qtdeclarative5-dev  libgtest-dev qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools) #dont think these are needed anymore but coudl be: python3 python3-dev glibc-source)
    sudo apt-get -y --ignore-missing install "${pkgs[@]}"
}


installExif(){
    
    #install exiftool
    wget http://exiftool.org/Image-ExifTool-12.58.tar.gz || exit 1
    tar -xf Image-ExifTool-12.58.tar.gz
    rm -rf Image-ExifTool-12.58.tar.gz
    cd Image-ExifTool-12.58
    perl Makefile.PL
    make test
    sudo make install
    cd ..
    rm -rf Image-ExifTool-12.58
    wget http://exiftool.org/cpp_exiftool/cpp_exiftool.tar.gz || exit 1
    tar -xf cpp_exiftool.tar.gz
    rm -rf cpp_exiftool.tar.gz
    cd cpp_exiftool
    make
    sudo make install
    cd .. 


}



#https://docs.opencv.org/3.4/d7/d9f/tutorial_linux_install.html

installOpenCV2(){
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

}


#main, calls functions already defined
getPrerequisites
installExif
installOpenCV2 




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