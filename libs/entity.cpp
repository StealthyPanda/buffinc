#include "../inc/entity.h"

entity::entity()
{
	center = Vector3(0, 0, 0);
	direction = Vector3(1, 0, 0);
	points = NULL;
	npoints = 0;
}

entity::entity(const Vector3& c)
{
	center = c;
	direction = Vector3(1, 0, 0);
	points = NULL;
	npoints = 0;
}

entity::entity(const Vector3& c, const Vector3& d)
{
	center = c;
	direction = d;
	points = NULL;
	npoints = 0;
}

entity::entity(const entity& e)
{
	center = e.center;
	direction = e.direction;
	points = e.points;
	npoints = e.npoints;
}

entity::~entity()
{
}


entity* entity::translate(const Vector3& delta)
{
	this->center = this->center + delta;
	return (this);
}

entity* entity::translate(long double dx, long double dy, long double dz)
{
	return (this->translate(Vector3(dx, dy, dz)));
}

entity* entity::translateTo(const Vector3& location)
{
	center = location;
	return this;
}

entity* entity::rotate(const Quaternion& rotor)
{
	Quaternion::rotate(direction, rotor);

	if (points != NULL)
	{
		for (int i = 0; i < npoints; ++i)
		Quaternion::rotate(points[i], rotor);
	}

	return this;
}

entity* entity::rotate(long double angleinradians, const Vector3& axis)
{
	Quaternion rotor = Quaternion::getRotor(angleinradians, axis);
	
	Quaternion::rotate(direction, rotor);

	if (points != NULL)
	{
		for (int i = 0; i < npoints; ++i)
		Quaternion::rotate(points[i], rotor);
	}	

	return this;
}

entity* entity::rotateTo(const Vector3& orientation)
{
	rotate(Quaternion::getRotor(direction, orientation));
	return this;
}


entity* entity::globalRotate(const Quaternion& rotor)
{
	Quaternion::rotate(center, rotor);
	return this;
}

entity* entity::globalRotate(long double angleinradians, const Vector3& axis)
{
	Quaternion::rotate(center, angleinradians, axis);
	return this;
}