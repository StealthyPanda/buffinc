#pragma once

#include "plane.h"

class ray
{
public:
	Vector3 point, direction;

	ray(const Vector3& point, const Vector3& direction);
	~ray();
	
	static ray getRay(const Vector3& from, const Vector3& to);

	Vector3 intersects(const plane& p);
};

ray getRay(const Vector3& from, const Vector3& to);