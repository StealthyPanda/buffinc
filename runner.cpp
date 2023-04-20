#include <iostream>

#include "./inc/ray.h"

#define pi 3.141592

int main()
{
	using namespace std;
	cout << "Hajimemashite" << endl;
	
	Vector3 i(1, 0, 0), j(0, 1, 0), k(0, 0, 1);

	cout << dot(Vector3(3, 0, -0.333333), Vector3(-1, 0, 0)) << endl;

	Vector3 planepoints[] = {
		Vector3(3, 1, -1), Vector3(3, -1, -1), Vector3(3, 0, 1)
	};
	plane tri(planepoints);
	cout << tri.center << tri.direction << endl;	

	ray sling = getRay(Vector3(0, 0, 0), i);

	cout << sling.point << sling.direction << endl;
	cout << sling.intersects(planepoints) << endl;

	return 0;
}