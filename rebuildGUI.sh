cd src/QT
cp ../../gui.ui . 
if [$? -ne 0]; then
    echo "ERROR. please copy gui.ui into the main directory"
    exit 1
fi
uic gui.ui > qtWindow.h
if [$? -ne 0]; then
    echo "Error. please ensure that gui.ui is a valid .ui file from QT creator"
    exit 1
cd ../..
rm gui.ui
