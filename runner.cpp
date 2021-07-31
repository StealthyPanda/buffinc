#include <iostream>
#include "Vector3.h"
using namespace std;

int main()
{
	Vector3 v = Vector3(1, 2, 3);
	Vector3 y = Vector3(4, 5, 6);

	Vector3 bruh = v + y;

	cout << v + y + v + y << endl;
	cout << bruh << endl;

	cout << (v * -1.2) + (y * -0.5) << endl;
	

	//cout << (v1 * -1.0) + (v2 * 1.2) << endl;

	return 0;
}