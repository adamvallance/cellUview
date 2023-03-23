

#if cmake version less than 3.11 then build from source
checkCMAKE(){
cmakeVerOutput=$(cmake --version)
cmakeVer=$(echo $cmakeVerOutput | cut -d' ' -f 3)
cmakeMajor=$(echo $cmakeVer | cut -d'.' -f 1)
cmakeMinor=$(echo $cmakeVer | cut -d'.' -f 2) 
echo $cmakeMajor
echo $cmakeMinor
if [ $cmakeMajor -lt 3 ]
then
    buildCMAKE3_11
    return
fi
if [ $cmakeMajor -eq 3 ]
then
    if [ $cmakeMinor -lt 11 ]
    then
        buildCMAKE3_11
        return
    fi
fi

}

#builds cmake 3.11 from source and installs
buildCMAKE3_11(){
#save current working directory to return upon completion   
cwd=$(pwd)

mkdir ~/temp && cd ~/temp
wget cmake.org/files/v3.11/cmake-3.11.0.tar.gz
tar -xzvf cmake-3.11.0.tar.gz
cd cmake-3.11.0/
./bootstrap
make -j$(nproc)
sudo make install
#remove temp folder?
echo "note that new cmake version will not be recognised until new vscode terminal is started"
cd $cwd

}

checkCMAKE