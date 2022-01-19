#ifndef _Quats_
#define _Quats_

#ifndef _Vector3_
#define _Vector3_
#include "Vector3.h"
#endif

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

class Quaternion
{

public:
	long double w;
	Vector3 imaginarypart;

	Quaternion();
	Quaternion(long double w, long double x, long double y, long double z);
	Quaternion(long double realpartparam, Vector3 imaginarypartparam);

	std::string getStringRepresentation();
	long double getMagnitude();

	Quaternion getConjugate();

	Quaternion getNormalised();
	void normalise();

	Quaternion getFiltered();
	void filter();

	static Quaternion getRotor(long double anglieinradians, Vector3 axis);
	static Quaternion getRotor(Vector3 initial, Vector3 final);

	static Vector3 getRotated(Vector3 vect, long double angleinradians, Vector3 axis);
	static Vector3 getRotated(Vector3 vect, Quaternion rotor);

};

//prints out the quaternion
std::ostream& operator<< (std::ostream& stream, Quaternion quat);


//adds 2 quaternions
Quaternion operator+ (const Quaternion q1, const Quaternion q2);

//multiplies 2 quaternions
Quaternion operator* (const Quaternion q1, const Quaternion q2);

//multiplies quaternion by scalar
Quaternion operator* (const Quaternion q1, long double scalar);
Quaternion operator* (long double scalar, const Quaternion q1);


Vector3 getRotated(Vector3 vect, long double angleinradians, Vector3 axis);
Vector3 getRotated(Vector3 vect, Quaternion rotor);

void rotate(Vector3& vect, long double angleinradians, Vector3 axis);
void rotate(Vector3& vect, Quaternion rotor);

bool operator== (const Quaternion q1, const Quaternion q2);



#endif