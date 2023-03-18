#author adam vallance
#this script takes a gui.ui file from QT creator copied into the main directory and compiles into the header to be integrated into the main code.
cd src/QT
cp ../../gui.ui . 
if [ $? -ne 0 ]; then
    echo "ERROR. please copy gui.ui into the main directory"
    exit 1
fi
uic gui.ui > qtWindow.h
if [ $? -ne 0 ]; then
    echo "Error. please ensure that gui.ui is a valid .ui file from QT creator"
    exit 1
fi
cd ../..
rm gui.ui
echo "Sucessfully rebuilt GUI."
