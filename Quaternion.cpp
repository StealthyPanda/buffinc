#include <sstream>
#include <cstring>
#include <iostream>
#include <cmath>
#include "Vector3.h"
#include "Quaternion.h"

//just a c++ thing bruh
double dmod(double value)
{
	if (value < 0) value *= -1;
	return value;
}

Quaternion::Quaternion()
{
	w = 1;
	imaginarypart = Vector3(0, 0, 0);
}

Quaternion::Quaternion(double wbuff, double xbuff, double ybuff, double zbuff)
{
	w = wbuff;
	imaginarypart = Vector3(xbuff, ybuff, zbuff);
}

Quaternion::Quaternion(double realpartparam, Vector3 imaginarypartparam)
{
	w = realpartparam;
	imaginarypart = imaginarypartparam;
}



Quaternion operator+ (const Quaternion q1, const Quaternion q2)
{
	return Quaternion(q1.w + q2.w, q1.imaginarypart + q2.imaginarypart);
}

Quaternion operator* (const Quaternion q1, const Quaternion q2)
{
	double pureconst = q1.w * q2.w;
	Vector3 w1vect = q1.w * q2.imaginarypart;
	Vector3 w2vect = q2.w * q1.imaginarypart;
	double dot = -1 * dotproduct(q1.imaginarypart, q2.imaginarypart);
	Vector3 cross = crossproduct(q1.imaginarypart, q2.imaginarypart);

	Quaternion constants = Quaternion(pureconst + dot, Vector3(0, 0, 0));
	Quaternion vectors = Quaternion(0, w1vect + w2vect + cross);

	Quaternion product = constants + vectors;

	return product;
}

Quaternion operator* (const Quaternion q1, double value)
{
	return Quaternion(q1.w * value, q1.imaginarypart * value);
}

Quaternion operator* (double value, const Quaternion q1)
{
	return q1 * value;
}

std::string Quaternion::getStringRepresentation()
{

	std::ostringstream bruh;
	bruh << "(" << w << ", " << imaginarypart.x << ", " << imaginarypart.y << ", " << imaginarypart.z << ")";
	return bruh.str();

}

std::ostream& operator<< (std::ostream& stream, Quaternion quat)
{
	stream << quat.getStringRepresentation();
	return stream;
}

double Quaternion::getMagnitude()
{
	return std::pow((w * w) + (imaginarypart.x * imaginarypart.x) + (imaginarypart.y * imaginarypart.y) + (imaginarypart.z * imaginarypart.z), 0.5);
}

Quaternion Quaternion::getNormalised()
{
	return Quaternion(*this * (1/getMagnitude()));
}

void Quaternion::normalise()
{
	double mag = getMagnitude();
	w *= (1/mag);
	imaginarypart = imaginarypart * (1/mag);
}

void Quaternion::filter()
{
	double threshold = std::pow(10, -8);
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


Quaternion Quaternion::getRotor(double angleinradians, Vector3 axis)
{
	axis.normalise();
	angleinradians /= 2;
	return Quaternion(std::cos(angleinradians), std::sin(angleinradians) * axis);
}

Quaternion Quaternion::getRotor(Vector3 initial, Vector3 final)
{
	double angle = std::acos(dotproduct(initial, final)/(initial.getMagnitude() * final.getMagnitude()));
	//angle /= 2;
	Vector3 axis = crossproduct(initial, final).getNormalised();
	//std::cout << "AXIS: " << axis << std::endl;
	return getRotor(angle, axis);
}


Quaternion Quaternion::getConjugate()
{
	return Quaternion(w, -1 * imaginarypart);
}

Vector3 Quaternion::getRotated(Vector3 vect, double angleinradians, Vector3 axis)
{
	Quaternion rotor = Quaternion::getRotor(angleinradians, axis);
	Quaternion rotted = (rotor * Quaternion(0, vect)) * rotor.getConjugate();

	return rotted.imaginarypart;
}

Vector3 Quaternion::getRotated(Vector3 vect, Quaternion rotor)
{
	Quaternion rotted = (rotor * Quaternion(0, vect)) * rotor.getConjugate();

	return rotted.imaginarypart;
}

Vector3 getRotated(Vector3 vect, double angleinradians, Vector3 axis)
{
	Quaternion rotor = Quaternion::getRotor(angleinradians, axis);
	Quaternion rotted = (rotor * Quaternion(0, vect)) * rotor.getConjugate();

	return rotted.imaginarypart;
}

Vector3 getRotated(Vector3 vect, Quaternion rotor)
{
	Quaternion rotted = (rotor * Quaternion(0, vect)) * rotor.getConjugate();

	return rotted.imaginarypart;
}

void rotate(Vector3& vect, double angleinradians, Vector3 axis)
{

	vect = getRotated(vect, angleinradians, axis);

}

void rotate(Vector3& vect, Quaternion rotor)
{

	vect = getRotated(vect, rotor);

}