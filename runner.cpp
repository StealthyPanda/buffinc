#include <iostream>

#include "./inc/color.h"
// #include "./inc/camera.h"

#define pi 3.141592

int main()
{
	using namespace std;
	cout << "Hajimemashite" << endl;

	color bruh = rgb(69, 42, 31), back = hsv(bruh.h, bruh.s, bruh.v);
	cout << (int) bruh.r << " " << (int) back.r << endl;
	cout << (int) bruh.g << " " << (int) back.g << endl;
	cout << (int) bruh.b << " " << (int) back.b << endl;
	// cout << (int) bruh.r << ", " << (int) bruh.g << ", " << (int) bruh.b << endl;

	// double yo = 29;
	// cout << yo/5 << endl;

	return 0;
}


// int main()
// {
// 	using namespace std;
// 	cout << "Hajimemashite" << endl;
	
// 	Vector3 i(1, 0, 0), j(0, 1, 0), k(0, 0, 1), o(0, 0, 0);

// 	// cout << dot(Vector3(3, 0, -0.333333), Vector3(-1, 0, 0)) << endl;

// 	Vector3 planepoints[] = {
// 		Vector3(3, 0, 0), Vector3(3, -2, 0), Vector3(3, 0, 2),
// 	};
// 	plane tri(planepoints);

// 	// plane another = plane(tri);
// 	// another.translate(Vector3(0, -5, 1));
// 	// cout << "tri stuff: " << tri.center << tri.direction << endl;
// 	// cout << "another stuff: " << another.center << another.direction << endl;
// 	// return 0;

// 	camera cam;
// 	// cam.rotate(pi/6, -j);

// 	plane* viewables[] = { &tri };

// 	for (int j = 0; j < 120; ++j)
// 	{
// 		cam.capture(viewables, (sizeof(viewables)/sizeof(plane*)));
// 		// viewables[0]->rotate(pi/5, i);
// 		// viewables[0]->translate(Vector3(1, 0, 0));
// 		tri.rotate(pi/60, k);

// 		// cam.rotate(pi/60, k);
// 		// tri.translate(Vector3(0, 1, 0));
// 		// cout << viewables[0].center << viewables[0].points[0] << endl;
// 	}

// 	char buff;
// 	// cin >> buff;

// 	return 0;
// }