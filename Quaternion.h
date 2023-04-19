#pragma once

#include <iostream>

class Quaternion
{

public:
	long double w;
	Vector3 imaginarypart;

	Quaternion();
	Quaternion(long double w, long double x, long double y, long double z);
	Quaternion(long double realpartparam, const Vector3& imaginarypartparam);
	Quaternion(const Quaternion& q);

	std::string getStringRepresentation() const;
	long double getMagnitude();

	Quaternion getConjugate() const;

	Quaternion getNormalised();
	void normalise();

	Quaternion getFiltered();
	void filter();

	static Quaternion getRotor(long double anglieinradians, const Vector3& axis);
	static Quaternion getRotor(const Vector3& initial, const Vector3& final);

	static Vector3 getRotated(const Vector3& vect, long double angleinradians, const Vector3& axis);
	static Vector3 getRotated(const Vector3& vect, const Quaternion& rotor);

};

//prints out the quaternion
std::ostream& operator<< (std::ostream& stream, const Quaternion& quat);


//adds 2 quaternions
Quaternion operator+ (const Quaternion& q1, const Quaternion& q2);

//subs 2 quaternions
Quaternion operator- (const Quaternion& q1, const Quaternion& q2);
Quaternion operator- (const Quaternion& quat);

//multiplies 2 quaternions
Quaternion operator* (const Quaternion& q1, const Quaternion& q2);

//multiplies quaternion by scalar
Quaternion operator* (const Quaternion& q1, long double scalar);
Quaternion operator* (long double scalar, const Quaternion& q1);

//checks if 2 quaterions are equal
bool operator== (const Quaternion& q1, const Quaternion& q2);

Vector3 getRotated(const Vector3& vect, long double angleinradians, const Vector3& axis);
Vector3 getRotated(const Vector3& vect, const Quaternion& rotor);

void rotate(Vector3& vect, long double angleinradians, const Vector3& axis);
void rotate(Vector3& vect, const Quaternion& rotor);

