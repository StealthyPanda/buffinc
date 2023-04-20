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

bool ray::intersects(const plane& p)
{
	// std::cout << "inside intersect" << std::endl;
	// std::cout << p.center << p.direction << std::endl;
	long double lambda = dot(p.direction, p.center - this->point);
	// std::cout << lambda << std::endl;

	lambda /= dot(p.direction, this->direction);
	// std::cout << lambda << std::endl;

	if (lambda <= 0) return false;

	Vector3 intersection = this->point + (this->direction * lambda);

	// return intersection;

	// std::cout << "intersection point: " << intersection << std::endl;

	bool c1, c2, c3;

	Vector3 a = p.points[0] + p.center, b = p.points[1] + p.center, c = p.points[2] + p.center;

	c1 = dot(cross(b - a, intersection - a) , p.direction) >= 0;
	c2 = dot(cross(c - b, intersection - b) , p.direction) >= 0;
	c3 = dot(cross(a - c, intersection - c) , p.direction) >= 0;

	// std::cout << "conditions: " << c1 << c2 << c3 << std::endl;
	// std::cout << "conditions: " << c1 << c2 << c3 << std::endl;

	// std::cout << dot(cross(p.points[1] - p.points[0], intersection - p.points[0]) , p.direction) <<
	// dot(cross(p.points[2] - p.points[1], intersection - p.points[1]) , p.direction) <<
	// dot(cross(p.points[0] - p.points[2], intersection - p.points[2]) , p.direction) << std::endl;

	if (c1 and c2 and c3) return true;
	if ((!c1) and (!c2) and (!c3)) return true;
	return false;
}



ray getRay(const Vector3& from, const Vector3& to)
{
	return ray::getRay(from, to);
}