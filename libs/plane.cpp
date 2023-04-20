#include "../inc/plane.h"
#include "../inc/camera.h"
#include "../inc/color.h"


plane::plane(Vector3 *points)
{
	this->points = points;
	this->npoints = 3;
	this->basecolor = rgb(128, 128, 128);

	this->center = points[0] + points[1] + points[2];
	this->center = this->center/3;

	Vector3 bminusa = points[1] - points[0], cminusa = points[2] - points[1];

	this->direction = cross(bminusa, cminusa);
	this->direction.normalise();
	this->normal = this->direction;

	this->points[0] = this->points[0] - this->center;
	this->points[1] = this->points[1] - this->center;
	this->points[2] = this->points[2] - this->center;

	this->newpoints = false;
}

plane::plane(Vector3 *points, const color& bc)
{
	this->points = points;
	this->npoints = 3;
	this->basecolor = bc;

	this->center = points[0] + points[1] + points[2];
	this->center = this->center/3;

	Vector3 bminusa = points[1] - points[0], cminusa = points[2] - points[1];

	this->direction = cross(bminusa, cminusa);
	this->direction.normalise();
	this->normal = this->direction;

	this->points[0] = this->points[0] - this->center;
	this->points[1] = this->points[1] - this->center;
	this->points[2] = this->points[2] - this->center;

	this->newpoints = false;
}

plane::plane(const plane& p)
{
	this->center = Vector3(p.center);
	this->normal = Vector3(p.normal);
	this->direction = Vector3(p.direction);
	this->npoints = 3;
	this->basecolor = (p.basecolor);

	this->points = new Vector3[3];
	for (int i = 0; i < 3; ++i)
	{
		this->points[i] = Vector3(p.points[i].x, p.points[i].y, p.points[i].z);
	}

	this->newpoints = true;
}

plane::~plane()
{
	if (this->newpoints) delete[] this->points;
}

plane* plane::rotate(const Quaternion& rotor)
{
	entity::rotate(rotor);
	normal = direction;
	return this;
}

plane* plane::rotate(long double angleinradians, const Vector3& axis)
{
	entity::rotate(angleinradians, axis);
	normal = direction;
	return this;
}


