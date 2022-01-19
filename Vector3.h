#ifndef _Vector3_
#define _Vector3_


#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif





class Vector3
{

public:
	long double x, y, z;

	Vector3();
	Vector3(long double val);
	Vector3(long double xbuff, long double ybuff, long double zbuff);
	Vector3(const Vector3& v1);

	std::string getStringRepresentation();

	Vector3 getMultiplied(long double value);
	void multiply(long double value);

	long double getMagnitude();

	Vector3 getNormalised();
	void normalise();

	Vector3 getFiltered();
	void filter();

};

//TODO (in general): reach maximum efficiency

//prints the vector out.
std::ostream& operator<< (std::ostream& stream, Vector3 vector);
//std::ostream& operator<< (std::ostream& stream, Vector3 vector);
//cannot chain additions together. I know.
//edit: fixed it;
//nvm  its broken again.
//nvm fixed it again. can chain any operations.


//adds two vectors.
Vector3 operator+ (const Vector3 v1, const Vector3 v2);
//same thing for multiplication and all other operations actually;
//fixed this too;
//nope still broken.
//completely fixed.

Vector3 operator- (const Vector3 v1, const Vector3 v2);


//multiplies a vector by a scalar. order obviously doesnt matter.
Vector3 operator* (const Vector3 v1, const long double value);
Vector3 operator* (const long double value, const Vector3 v1);

//gives dotproduct of 2 vectors.
long double dotproduct(const Vector3 v1, const Vector3 v2);

//fives crossproduct of 2 vectors.
Vector3 crossproduct(const Vector3 v1, const Vector3 v2);

//returns true iff x, y, z, components of both are equal
bool operator== (const Vector3 v1, const Vector3 v2);


#endif