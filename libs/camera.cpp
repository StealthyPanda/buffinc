#include <iostream>
#include <sstream>
#include "../inc/camera.h"


camera::camera()
{
	center = Vector3(0, 0, 0);
	direction = Vector3(1, 0, 0);
	film = new raster(720, 1280);
	nframe = 0;

	dist = 0.1;
	width = 0.128;
	height = 0.072;

	npoints = 2;
	points = new Vector3[2];
	points[0] = center + Vector3(dist, width/2.0, height/2.0);
	points[1] = center + Vector3(dist, -width/2.0, -height/2.0);
}

camera::~camera()
{
	delete film;
}

void camera::capture()
{
	std::ostringstream buffer;
	buffer << "./camera/buffer_" << nframe << ".txt";
	film->writetofile(buffer.str());
	nframe++;
}
