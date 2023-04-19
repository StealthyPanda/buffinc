#include <iostream>

#include "./inc/plane.h"

#define pi 3.141592

int main()
{
	using namespace std;
	cout << "Hajimemashite" << endl;
	
	Vector3 i(1, 0, 0), j(0, 1, 0), k(0, 0, 1);

	Vector3 planepoints[] = {
		Vector3(3, 0, 0), Vector3(3, -3, 0), Vector3(6, 0, 0)
	};

	plane test(planepoints);

	cout << test.center << test.normal << test.direction << endl;

	test.rotate(pi/2, -j);

	cout << test.center << test.normal << test.direction << endl;
	cout << test.points[0] + test.center << test.points[1] + test.center << test.points[2] + test.center << endl;
	// cout << planepoints[0] << planepoints[1] << planepoints[2] << endl;


	return 0;
}