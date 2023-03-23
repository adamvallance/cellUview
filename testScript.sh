
getCMAKE3_11(){


mkdir ~/temp && cd ~/temp
wget cmake.org/files/v3.11/cmake-3.11.0.tar.gz
tar -xzvf cmake-3.11.0.tar.gz
cd cmake-3.11.0/
./bootstrap
make -j$(nproc)
sudo make install

}