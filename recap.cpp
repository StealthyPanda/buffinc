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
    Vector3 morepoints[] = {p1, p2, p3, p4};

    Plane plane1(points, 4), plane2(morepoints, 4);

    plane1.display();
    cout << endl;
    plane2.display();
    cout << endl;


    plane1.rotateglobal(M_PI_2, Vector3(0, 0, 1));
    plane2.rotateglobal(M_PI_2, Vector3(0, 0, 1));


    plane1.display();
    cout << endl;
    plane2.display();
    cout << endl;

    return 0;
}