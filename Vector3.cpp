#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include "Vector3.h"

double mod(double value)
{
	if (value < 0) value *= -1;
	return value;
}

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(double val)
{
	x = val;
	y = val;
	z = val;
}

Vector3::Vector3(double xbuff, double ybuff, double zbuff)
{
	x = xbuff;
	y = ybuff;
	z = zbuff;
}

Vector3::Vector3(const Vector3& v1)
{
	x = v1.x;
	y = v1.y;
	z = v1.z;
}

std::string Vector3::getStringRepresentation()
{

	std::ostringstream bruh;
	bruh << "(" << x << ", " << y << ", " << z << ")";
	return bruh.str();

}

Vector3 Vector3::getMultiplied(double value)
{
	return (*this * value);
}

void Vector3::multiply(double value)
{
	x *= value;
	y *= value;
	z *= value;
}

std::ostream& operator<< (std::ostream& stream, Vector3 vector)
{
	stream << vector.getStringRepresentation();
	return stream;
}


Vector3 operator+ (const Vector3 v1, const Vector3 v2)
{
	return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3 operator* (const Vector3 v1, const double value)
{
	return Vector3(v1.x * value, v1.y * value, v1.z * value);
}

Vector3 operator* (const double value, const Vector3 v1)
{
	return Vector3(v1.x * value, v1.y * value, v1.z * value);
}


double dotproduct(const Vector3 v1, const Vector3 v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

Vector3 crossproduct(const Vector3 v1, const Vector3 v2)
{

	return Vector3(((v1.y * v2.z) - (v2.y * v1.z)), ((v2.x * v1.z) - (v1.x * v2.z)), ((v1.x * v2.y) - (v2.x * v1.y)));

}

double Vector3::getMagnitude()
{
	return std::pow((x * x) + (y * y) + (z * z), 0.5);
}

Vector3 Vector3::getNormalised()
{
	return Vector3(*this * (1/getMagnitude()));
}

void Vector3::normalise()
{
	double mag = getMagnitude();

	x *= (1/mag);
	y *= (1/mag);
	z *= (1/mag);
}

void Vector3::filter()
{
	double threshold = std::pow(10, -8);
	if (mod(x) <= threshold) x = 0;
	if (mod(y) <= threshold) y = 0;
	if (mod(z) <= threshold) z = 0;
}

Vector3 Vector3::getFiltered()
{
	Vector3 buff = Vector3(*this);
	buff.filter();
	return buff;
}

/*Vector3 Vector3::getRotated(double angleinradians, Vector3 axis)
{
	return Quaternion::rotate(*this, angleinradians, axis);
}


Vector3 Vector3::getRotated(Quaternion rotor)
{
	return Quaternion::rotate(*this, rotor);
}

void Vector3::rotate(double angleinradians, Vector3 axis)
{
	Vector3 rotted = Quaternion::rotate(*this, angleinradians, axis);
	x = rotted.x;
	y = rotted.y;
	z = rotted.z;
}

void Vector3::rotate(Quaternion rotor)
{
	Vector3 rotted = Quaternion::rotate(*this, rotor);
	x = rotted.x;
	y = rotted.y;
	z = rotted.z;
}*/