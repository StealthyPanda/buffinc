#ifndef _Vector3_
#define _Vector3_

#include <cstring>
#include <iostream>

class Vector3
{

public:
	double x, y, z;

	Vector3();
	Vector3(double val);
	Vector3(double xbuff, double ybuff, double zbuff);
	Vector3(const Vector3& v1);

	std::string getStringRepresentation();

	Vector3 getMultiplied(double value);
	void multiply(double value);

};


std::ostream& operator<< (std::ostream& stream, Vector3 vector);
//std::ostream& operator<< (std::ostream& stream, Vector3 vector);
//cannot chain additions together. I know.
//edit: fixed it;
//nvm  its broken again.
//nvm fixed it again. can chain any operations.
Vector3 operator+ (const Vector3 v1, const Vector3 v2);
//same thing for multiplication and all other operations actually;
//fixed this too;
//nope still broken.
//completely fixed.
Vector3 operator* (const Vector3 v1, const double value);
Vector3 operator* (const double value, const Vector3 v1);



#endif