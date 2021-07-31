#ifndef _Quats_
#define _Quats_

#include "Vector3.h"
#include <cstring>
#include <iostream>

class Quaternion
{

public:
	double w;
	Vector3 imaginarypart;

	Quaternion();
	Quaternion(double w, double x, double y, double z);
	Quaternion(double realpartparam, Vector3 imaginarypartparam);

	std::string getStringRepresentation();
	double getMagnitude();

	Quaternion getConjugate();

	Quaternion getNormalised();
	void normalise();
	Quaternion getFiltered();
	void filter();

	static Quaternion getRotor(double anglieinradians, Vector3 axis);
	static Quaternion getRotor(Vector3 initial, Vector3 final);

	static Vector3 rotate(Vector3 vect, double angleinradians, Vector3 axis);
	static Vector3 rotate(Vector3 vect, Quaternion rotor);

};

//prints out the quaternion
std::ostream& operator<< (std::ostream& stream, Quaternion quat);


//adds 2 quaternions
Quaternion operator+ (const Quaternion q1, const Quaternion q2);

//multiplies 2 quaternions
Quaternion operator* (const Quaternion q1, const Quaternion q2);

//multiplies quaternion by scalar
Quaternion operator* (const Quaternion q1, double scalar);
Quaternion operator* (double scalar, const Quaternion q1);


Vector3 rotate(Vector3 vect, double angleinradians, Vector3 axis);
Vector3 rotate(Vector3 vect, Quaternion rotor);



#endif