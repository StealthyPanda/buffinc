#include <iostream>

#include "./inc/camera.h"

#define pi 3.141592

int main()
{
	using namespace std;
	cout << "Hajimemashite" << endl;
	
	Vector3 i(1, 0, 0), j(0, 1, 0), k(0, 0, 1), o(0, 0, 0);

	// cout << dot(Vector3(3, 0, -0.333333), Vector3(-1, 0, 0)) << endl;

	Vector3 planepoints[] = {
		Vector3(3, -10, 1), Vector3(3, -20, 3), Vector3(3, -10, 3),
	};
	plane tri(planepoints);

	// plane another = plane(tri);
	// another.translate(Vector3(0, -5, 1));
	// cout << "tri stuff: " << tri.center << tri.direction << endl;
	// cout << "another stuff: " << another.center << another.direction << endl;
	// return 0;

	camera cam;
	// cam.rotate(pi/6, -j);

	plane viewables[] = { tri };

	for (int j = 0; j < 2; ++j)
	{
		cam.capture(viewables, 1);
		tri.rotate(pi/2, i);
	}

	char buff;
	// cin >> buff;

	return 0;
}