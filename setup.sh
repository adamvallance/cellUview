#adapted from github.com/albanjoseph/signapse

sudo apt install cmake gcc build-essential qtbase5-dev qtdeclarative5-dev  libgtest-dev qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y 
##added more libraries to hopefully fix qt5-default not working


CV_VERSION="69357b1e88680658a07cffde7678a4d697469f03"
## Download OpenCV code
printf "Downloading OpenCV ..."
if [ ! -d "opencv_src" ]; then
  printf "\n"
  wget "https://github.com/opencv/opencv/archive/$CV_VERSION.zip" || exit 1
  unzip -q $CV_VERSION
  mv "opencv-$CV_VERSION" opencv_src
else
  printf " skipped download\n"
fi
if [ ! -d "opencv_build" ]; then
  printf "\n"
  mkdir -p opencv_build
  cd opencv_build
  #install with only the nessessary packages - reduces build time
  cmake -DBUILD_LIST=dnn,improc,videoio, -DCMAKE_BUILD_TYPE=Release ../opencv_src || exit 1
  #set make jobs to 4 - reduces build time
  make -j4 || exit 1
  #maybe add something to remove if build goes wrong?
  cd ..
  rm 69357b1e88680658a07cffde7678a4d697469f03.zip #remove zip download
else
  printf " skipped build\n"
fi
