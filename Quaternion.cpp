#include <sstream>
#include <cstring>
#include <iostream>
#include <cmath>
#include "Vector3.h"
#include "Quaternion.h"

//just a c++ thing bruh
long double dmod(long double value)
{
	if (value < 0) value *= -1;
	return value;
}

Quaternion::Quaternion()
{
	w = 1;
	imaginarypart = Vector3(0, 0, 0);
}

Quaternion::Quaternion(const Quaternion& q)
{
	w = q.w;
	imaginarypart = Vector3(q.imaginarypart);
}

Quaternion::Quaternion(long double wbuff, long double xbuff, long double ybuff, long double zbuff)
{
	w = wbuff;
	imaginarypart = Vector3(xbuff, ybuff, zbuff);
}

Quaternion::Quaternion(long double realpartparam, const Vector3& imaginarypartparam)
{
	w = realpartparam;
	imaginarypart = imaginarypartparam;
}

std::string Quaternion::getStringRepresentation() const
{

	std::ostringstream bruh;
	bruh << "(" << w << ", " << imaginarypart.x << ", " << imaginarypart.y << ", " << imaginarypart.z << ")";
	return bruh.str();

}


long double Quaternion::getMagnitude()
{
	return std::pow((w * w) + (imaginarypart.x * imaginarypart.x) + (imaginarypart.y * imaginarypart.y) + (imaginarypart.z * imaginarypart.z), 0.5);
}

Quaternion Quaternion::getConjugate() const
{
	return Quaternion(w, -imaginarypart);
}

Quaternion Quaternion::getNormalised()
{
	long double invmag = (1/getMagnitude());
	return Quaternion(w * invmag, imaginarypart * invmag);
}

void Quaternion::normalise()
{
	long double mag = getMagnitude();
	w *= (1/mag);
	imaginarypart = imaginarypart * (1/mag);
}

void Quaternion::filter()
{
	// long double threshold = std::pow(10, -8);
	if (dmod(w) <= threshold) w = 0;
	if (dmod(imaginarypart.x) <= threshold) imaginarypart.x = 0;
	if (dmod(imaginarypart.y) <= threshold) imaginarypart.y = 0;
	if (dmod(imaginarypart.z) <= threshold) imaginarypart.z = 0;
}

Quaternion Quaternion::getFiltered()
{
	Quaternion buff = Quaternion(*this);
	buff.filter();
	return buff;
}




std::ostream& operator<< (std::ostream& stream, const Quaternion& quat)
{
	stream << quat.getStringRepresentation();
	return stream;
}


Quaternion operator+ (const Quaternion& q1, const Quaternion& q2)
{
	return Quaternion(q1.w + q2.w, q1.imaginarypart + q2.imaginarypart);
}

Quaternion operator- (const Quaternion& q1, const Quaternion& q2)
{
	return Quaternion(q1.w - q2.w, q1.imaginarypart - q2.imaginarypart);
}

Quaternion operator- (const Quaternion& quat)
{
	return Quaternion(-quat.w, -quat.imaginarypart);
}

Quaternion operator* (const Quaternion& q1, const Quaternion& q2)
{
	long double pureconst = q1.w * q2.w;
	Vector3 w1vect = q1.w * q2.imaginarypart;
	Vector3 w2vect = q2.w * q1.imaginarypart;
	long double dotproduct = -1 * dot(q1.imaginarypart, q2.imaginarypart);
	Vector3 crossproduct = cross(q1.imaginarypart, q2.imaginarypart);

	Quaternion constants = Quaternion(pureconst + dotproduct, Vector3(0, 0, 0));
	Quaternion vectors = Quaternion(0, w1vect + w2vect + crossproduct);

	Quaternion product = constants + vectors;

	return product;
}

Quaternion operator* (const Quaternion& q1, long double value)
{
	return Quaternion(q1.w * value, q1.imaginarypart * value);
}

Quaternion operator* (long double value, const Quaternion& q1)
{
	return q1 * value;
}


bool operator== (const Quaternion& q1, const Quaternion& q2)
{
	return ((q1.w == q2.w) and (q1.imaginarypart == q2.imaginarypart));
}


Quaternion Quaternion::getRotor(long double angleinradians, const Vector3& axis)
{
	// axis.normalise();
	angleinradians /= 2;
	return Quaternion(std::cos(angleinradians), std::sin(angleinradians) * axis.getNormalised());
}

Quaternion Quaternion::getRotor(const Vector3& initial, const Vector3& final)
{
	long double angle = std::acos(dot(initial, final)/(initial.getMagnitude() * final.getMagnitude()));
	Vector3 axis = cross(initial, final);
	return Quaternion::getRotor(angle, axis);
}


Vector3 Quaternion::getRotated(const Vector3& vect, long double angleinradians, const Vector3& axis)
{
	Quaternion rotor = Quaternion::getRotor(angleinradians, axis);
	Quaternion rotted = (rotor * Quaternion(0, vect)) * rotor.getConjugate();

	return rotted.imaginarypart;
}

Vector3 Quaternion::getRotated(const Vector3& vect, const Quaternion& rotor)
{
	Quaternion rotted = (rotor * Quaternion(0, vect)) * rotor.getConjugate();

	return rotted.imaginarypart;
}

Vector3 getRotated(const Vector3& vect, long double angleinradians, const Vector3& axis)
{
	return Quaternion::getRotated(vect, angleinradians, axis);
}

Vector3 getRotated(const Vector3& vect, const Quaternion& rotor)
{
	return Quaternion::getRotated(vect, rotor);
}

void rotate(Vector3& vect, long double angleinradians, const Vector3& axis)
{
	vect = getRotated(vect, angleinradians, axis);
}

void rotate(Vector3& vect, const Quaternion& rotor)
{
	vect = getRotated(vect, rotor);
}