#include <iostream>
#include "Vector3.h"
using namespace std;

int main()
{

	Vector3 zero = Vector3();
	Vector3 scalar = Vector3(2);
	Vector3 cons = Vector3(1, 2, 3);

	Vector3 bruh = -1.0 * cons;
	Vector3 omg = 1.2 * scalar;
	Vector3 dude = bruh + omg;

	cout << bruh << endl;
	cout << omg << endl;
	cout << dude << endl;
	cout << (cons * -1) + ((scalar)) + zero << endl;

	return 0;
}