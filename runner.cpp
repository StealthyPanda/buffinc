#include <iostream>
#include "./inc/camera.h"


int main()
{
    using namespace std;

    cout << "Hajimemashite\n";

    camera cam;
    cam.printinfo();

    Vector3 points[] = {
        Vector3(2, 0, 0),
        Vector3(2, 1, 0),
        Vector3(2, 0, 1)
    };

    color bluegreen;
    bluegreen.b = 128;
    bluegreen.g = 128;
    bluegreen.r = 0;

    plane p(points, bluegreen);
    plane *ps[] = {&p};

    cam.capture(ps, sizeof(ps)/sizeof(plane*));

    return 0;
}