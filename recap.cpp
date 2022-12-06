#include <iostream>
#include "renderer.h"

#define _USE_MATH_DEFINES
#include <cmath>

int main()
{
    using namespace buffinc;
    using namespace std;

    Vector3 point1(0, 0, 0), point2(0, 2, 0), point3(0, 2, 2), point4(0, 0, 2);
    
    Vector3 p1(0, -2, -2), p2(0, 2, -2), p3(0, 2, 2), p4(0, -2, 2);

    Vector3 points[] = {point1, point2, point3, point4};

    Plane plane(points, 4);

    cout << plane << endl;
    cout << plane.getNormal() << endl << endl;

    Vector3 morepoints[4] = {p1, p2, p3, p4};

    plane = Plane(morepoints, 4);

    cout << plane << endl;
    cout << plane.getNormal() << endl << endl;

    return 0;
}