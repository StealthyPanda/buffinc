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

	std::string getStringRepresentation();

};


std::ostream& operator<< (std::ostream& stream, Vector3& vector);
//cannot chain additions together. I know.
Vector3 operator+ (Vector3& v1, Vector3& v2);
//same thing for multiplication and all other operations actually;
Vector3 operator* (Vector3& v1, double value);
Vector3 operator* (double value, Vector3& v1);



#endif