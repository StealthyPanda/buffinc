#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include "Vector3.h"

long double mod(long double value)
{
	if (value < 0) value *= -1;
	return value;
}

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
	this->isnull = false;
}

Vector3::Vector3(long double val)
{
	x = val;
	y = val;
	z = val;
	this->isnull = false;
}

Vector3::Vector3(bool isnull)
{
	this->isnull = isnull;
}


Vector3::Vector3(long double xbuff, long double ybuff, long double zbuff)
{
	x = xbuff;
	y = ybuff;
	z = zbuff;
	this->isnull = false;
}

Vector3::Vector3(const Vector3& v1)
{
	x = v1.x;
	y = v1.y;
	z = v1.z;
	this->isnull = v1.isnull;
}

std::string Vector3::getStringRepresentation()
{

	std::ostringstream bruh;
	bruh << "(" << x << ", " << y << ", " << z << ")";
	return bruh.str();

}

Vector3 Vector3::getMultiplied(long double value)
{
	return (*this * value);
}

void Vector3::multiply(long double value)
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

Vector3 operator* (const Vector3 v1, const long double value)
{
	return Vector3(v1.x * value, v1.y * value, v1.z * value);
}

Vector3 operator* (const long double value, const Vector3 v1)
{
	return Vector3(v1.x * value, v1.y * value, v1.z * value);
}

Vector3 operator- (const Vector3 v1, const Vector3 v2)
{
	return (v1 + (v2 * -1));
}


long double dotproduct(const Vector3& v1, const Vector3& v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

Vector3 crossproduct(const Vector3& v1, const Vector3& v2)
{

	return Vector3(((v1.y * v2.z) - (v2.y * v1.z)), ((v2.x * v1.z) - (v1.x * v2.z)), ((v1.x * v2.y) - (v2.x * v1.y)));

}

long double Vector3::getMagnitude()
{
	return std::pow((x * x) + (y * y) + (z * z), 0.5);
}

Vector3 Vector3::getNormalised()
{
	return Vector3(*this * (1/getMagnitude()));
}

void Vector3::normalise()
{
	long double mag = getMagnitude();

	x *= (1/mag);
	y *= (1/mag);
	z *= (1/mag);
}

void Vector3::filter()
{
	long double threshold = std::pow(10, -8);
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

bool operator== (const Vector3 v1, const Vector3 v2)
{
	return ((v1.x == v2.x) and (v1.y == v2.y) and (v1.z == v2.z));
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