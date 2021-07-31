#include <iostream>
#include "Vector3.h"
#include <cstring>
#include <sstream>

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