#include "Vector3.h"
#include "Quaternion.h"
#include <iostream>

#define pi 3.141592

int main()
{
	using namespace std;
	cout << "Hajimemashite" << endl;

	Vector3 i(1, 0, 0), j(0, 1, 0), k(0, 0, 1);
	Quaternion test(1, 2, 3, 4), thing(-4, -3, -2, -1);

	Vector3 newthing(0, 0, 22);

	cout << getRotated(newthing, Quaternion::getRotor(k, i)).getFiltered() << endl;
	cout << newthing << endl;
	cout << i << j << k << endl;
	// cout << newthing << endl;

	return 0;
}