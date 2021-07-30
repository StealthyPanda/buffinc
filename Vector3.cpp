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

std::string Vector3::getStringRepresentation()
{

	std::ostringstream bruh;
	bruh << "(" << x << ", " << y << ", " << z << ")";
	return bruh.str();

}

std::ostream& operator<< (std::ostream& stream, Vector3& vector)
{
	stream << vector.getStringRepresentation();
	return stream;
}

Vector3& operator+ (Vector3& v1, Vector3& v2)
{
	Vector3 sum = Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	static Vector3& ref = sum;
	return ref;
}

Vector3& operator* (Vector3& v1, double value)
{
	Vector3 product = Vector3(v1.x * value, v1.y * value, v1.z * value);
	static Vector3& ref = product;
	return ref;
}

Vector3& operator* (double value, Vector3& v1)
{
	Vector3 product = Vector3(v1.x * value, v1.y * value, v1.z * value);
	static Vector3& ref = product;
	return ref;
}