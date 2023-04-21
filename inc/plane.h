#pragma once

#include "entity.h"
#include "color.h"

class plane : public entity
{
public:
	color basecolor, shade;

	Vector3 normal, *globallight = NULL;

	bool newpoints;

	//note that while the *points member stores vectors in LOCAL coordinated wrt center in
	//entities, here points is meant to be GLOBAL coordinates, and the planes constructor
	//will internally convert them to local ones. This exception is ONLY for planes.
	//also planes are only tri. no quads.
	plane(Vector3 *points);
	plane(Vector3 *points, const color& bc);
	plane(const plane& p);
	~plane();

	plane* rotate(const Quaternion& rotor);
	plane* rotate(long double angleinradians, const Vector3& axis);

	// void calculatehsv();
};