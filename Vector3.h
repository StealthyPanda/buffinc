#ifndef _Vector3_
#define _Vector3_


#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif





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

	double getMagnitude();

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


//multiplies a vector by a scalar. order obviously doesnt matter.
Vector3 operator* (const Vector3 v1, const double value);
Vector3 operator* (const double value, const Vector3 v1);

//gives dotproduct of 2 vectors.
double dotproduct(const Vector3 v1, const Vector3 v2);

//fives crossproduct of 2 vectors.
Vector3 crossproduct(const Vector3 v1, const Vector3 v2);


#endif