#pragma once

#include "Vector3.h"
#include "Quaternion.h"

class entity
{
public:
	Vector3 center, direction, *points;
	short npoints;

	entity();
	entity(const Vector3& c);
	entity(const Vector3& c, const Vector3& d);
	entity(const entity& e);
	~entity();

	entity* translate(const Vector3& delta);
	entity* translate(long double dx, long double dy, long double dz);

	entity* translateTo(const Vector3& location);
	

	//NOTE: this is local rotate
	entity* rotate(const Quaternion& rotor);
	entity* rotate(long double angleinradians, const Vector3& axis);

	entity* rotateTo(const Vector3& orientation);

	//global rotation preserving local orientation
	entity* globalRotate(const Quaternion& rotor);
	entity* globalRotate(long double angleinradians, const Vector3& axis);
};