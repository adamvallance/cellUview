#include "camera.h"


int main()
{
    Camera spyBalloon;
    spyBalloon.start_stream();

    // Wait for a key press to stop the microscope
    waitKey(0);

    spyBalloon.stop_stream();

    return 0;
}