#pragma once

#include "entity.h"
#include "raster.h"
#include "plane.h"

class camera : public entity
{
public:
	unsigned nframe;
	raster *film;

	Vector3 localx, localy, localz, globallight;

	long double dist, width, height, ratio;

	camera();
	~camera();

	camera* rotate(const Quaternion& rotor);
	camera* rotate(long double angleinradians, const Vector3& axis);
	camera* rotateTo(const Vector3& orientation);

	void capture(plane **planes, int nplanes);

	void printinfo();
};

