#pragma once

#include "entity.h"
#include "raster.h"

class camera : public entity
{
public:
	unsigned nframe;
	raster *film;

	long double dist, width, height;

	camera();
	~camera();

	void capture();
};

