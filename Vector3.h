#pragma once

#include <iostream>
#include <cmath>

const long double threshold = std::pow(10, -6);


class Vector3
{

public:
	long double x, y, z;
	bool isnull;


	Vector3();
	Vector3(long double val);
	Vector3(long double xbuff, long double ybuff, long double zbuff);
	Vector3(const Vector3& v1);

	Vector3(bool isnull);

	std::string getStringRepresentation() const;

	Vector3 getMultiplied(long double value);
	void multiply(long double value);

	long double getMagnitude() const;

	Vector3 getNormalised() const;
	void normalise();

	Vector3 getFiltered();
	void filter();
};

//TODO (in general): reach maximum efficiency

//prints the vector out.
std::ostream& operator<< (std::ostream& stream, const Vector3& vector);


//adds two vectors.
Vector3 operator+ (const Vector3& v1, const Vector3& v2);

//subtracts two vectors
Vector3 operator- (const Vector3& v1, const Vector3& v2);
Vector3 operator- (const Vector3& v1);


//multiplies a vector by a scalar. order obviously doesnt matter.
Vector3 operator* (const Vector3& v1, const long double value);
Vector3 operator* (const long double value, const Vector3& v1);

//gives dotproduct of 2 vectors.
long double dot(const Vector3& v1, const Vector3& v2);

//fives crossproduct of 2 vectors.
Vector3 cross(const Vector3& v1, const Vector3& v2);

//returns true iff x, y, z, components of both are equal
bool operator== (const Vector3& v1, const Vector3& v2);

