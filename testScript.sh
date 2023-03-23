#SETUP script. Author Adam Vallance. This script installs prerequisite packages. Builds and installs cmake 
#if the version is insufficient, and then builds opencv (image processing) and also builds and installs exiv2 (for image metadata handling) and 

#installs prerequisite packages
getPrerequisites(){
    sudo apt update
    sudo apt upgrade
    pkgs=(gcc cmake build-essential libtool autoconf unzip wget qtbase5-dev qtdeclarative5-dev  libgtest-dev qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools)
    sudo apt-get -y --ignore-missing install "${pkgs[@]}"
}


#if cmake version less than 3.11 then build from source
checkCMAKE(){
cmakeVerOutput=$(cmake --version)
cmakeVer=$(echo $cmakeVerOutput | cut -d' ' -f 3)
cmakeMajor=$(echo $cmakeVer | cut -d'.' -f 1)
cmakeMinor=$(echo $cmakeVer | cut -d'.' -f 2) 
if [ $cmakeMajor -lt 3 ]
then

    installCMAKE3_11
    return
fi
if [ $cmakeMajor -eq 3 ]
then
    if [ $cmakeMinor -lt 11 ]
    then
        installCMAKE3_11
        return
    fi
fi
echo "CMake $cmakeVer is valid"

}

#builds cmake 3.11 from source and installs
installCMAKE3_11(){
echo "Current CMake Version not sufficient. Building and installing cmake 3.11"
#save current working directory to return upon completion   
cwd=$(pwd)

mkdir ~/temp && cd ~/temp
wget cmake.org/files/v3.11/cmake-3.11.0.tar.gz
tar -xzvf cmake-3.11.0.tar.gz
cd cmake-3.11.0/
./bootstrap
make -j$(nproc)
sudo make install
rm -rf temp
echo "note that new cmake version will not be recognised until new vscode terminal is started"
cd $cwd

}

installExiv(){
    mkdir temp && cd temp
    git clone https://github.com/Exiv2/exiv2
    cd exiv2
    mkdir build && cd build
    cmake -DCMAKE_BUILD_TYPE_Release ..
    cmake --build .
    ctest --verbose
    cmake --install .
}
 


#main, calls functions already defined
getPrerequisites
checkCMAKE
installExiv