#include "../inc/ray.h"
#include "../inc/plane.h"

ray::ray(const Vector3& point, const Vector3& direction)
{
	this->point = point;
	this->direction = direction;
	this->direction.normalise();
}

ray::~ray()
{
}

ray ray::getRay(const Vector3& from, const Vector3& to)
{
	Vector3 dir = to - from;
	dir.normalise();
	return ray(from, dir);
}

#include <iostream>

Vector3 ray::intersects(const plane& p)
{
	std::cout << "inside intersect" << std::endl;
	std::cout << p.center << p.direction << std::endl;
	long double lambda = dot(p.direction, p.center);
	std::cout << lambda << std::endl;

	lambda -= dot(p.direction, this->point);
	std::cout << lambda << std::endl;

	lambda /= dot(p.direction, this->direction);
	std::cout << lambda << std::endl;

	Vector3 intersection = this->point + (this->direction * lambda);

	return intersection;
}



ray getRay(const Vector3& from, const Vector3& to)
{
	return ray::getRay(from, to);
}