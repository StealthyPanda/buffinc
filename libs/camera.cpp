#include <iostream>
#include <sstream>
#include "../inc/camera.h"
#include "../inc/ray.h"
#include "../inc/plane.h"


camera::camera()
{
	center = Vector3(0, 0, 0);
	direction = Vector3(1, 0, 0);
	film = new raster(720, 1280);
	nframe = 0;

	dist = 0.5;
	width = 0.128 * 4;
	height = 0.072 * 4;

	ratio = width/film->cols;

	npoints = 2;
	points = new Vector3[2];
	points[0] = center + Vector3(dist, width/2.0, height/2.0);
	points[1] = center + Vector3(dist, -width/2.0, -height/2.0);

	localx = Vector3(1, 0, 0);
	localy = Vector3(0, 1, 0);
	localz = Vector3(0, 0, 1);
}

camera::~camera()
{
	delete film;
	delete[] points;
}

camera* camera::rotate(const Quaternion& rotor)
{
	entity::rotate(rotor);

	Quaternion::rotate(localx, rotor);
	Quaternion::rotate(localy, rotor);
	Quaternion::rotate(localz, rotor);

	return this;
}

camera* camera::rotate(long double angleinradians, const Vector3& axis)
{
	Quaternion rotor = Quaternion::getRotor(angleinradians, axis);

	entity::rotate(rotor);

	Quaternion::rotate(localx, rotor);
	Quaternion::rotate(localy, rotor);
	Quaternion::rotate(localz, rotor);

	return this;
}


camera* camera::rotateTo(const Vector3& orientation)
{
	Quaternion rotor = Quaternion::getRotor(direction, orientation);

	entity::rotate(rotor);

	Quaternion::rotate(localx, rotor);
	Quaternion::rotate(localy, rotor);
	Quaternion::rotate(localz, rotor);

	return this;
}

void camera::capture(plane *planes, int nplanes)
{

	// ray light = ray(Vector3(), Vector3());
	ray light = ray(Vector3(), Vector3());
	bool hit;

	for (unsigned i = 0; i < this->film->rows; ++i)
	{
		for (unsigned j = 0; j < this->film->cols; ++j)
		{
			light = getRay(this->center, this->points[0] - (ratio * ((localy * j) + (localz * i))));
			
			for (int m = 0; m < nplanes; ++m)
			{
				hit = light.intersects(planes[m]);
				if (hit)
				{
					film->matrix[i][j][0] = 255;
					film->matrix[i][j][1] = 255;
					break;
				}
			}

			// hit = light.intersects(planes[0]);
			// film.matrix[i][j][1] = (255 * hit);
			// film.matrix[i][j][2] = (255 * hit);
		}
		// std::cout << "Finished row "<< i << std::endl;
	}




	std::cout << "Capturing frame " << nframe << std::endl;
	std::ostringstream buffer;
	buffer << "./camera/buffer_" << nframe << ".txt";
	film->writetofile(buffer.str());
	nframe++;

	for (int i = 0; i < this->film->rows; ++i)
	{
		for (int j = 0; j < this->film->cols; ++j)
		{
			this->film->matrix[i][j][0] = 0;
			this->film->matrix[i][j][1] = 0;
			this->film->matrix[i][j][2] = 0;
		}
	}

}

void camera::printinfo()
{
	std::cout << "Camera:" << std::endl;
	std::cout << "Center: " << center.getFiltered() << " Direction: " << direction.getFiltered() << std::endl;
	std::cout << "localx: " << localx.getFiltered() << std::endl;
	std::cout << "localy: " << localy.getFiltered() << std::endl;
	std::cout << "localz: " << localz.getFiltered() << std::endl;
	std::cout << "tl: " << points[0] << " br: " << points[1] << std::endl;
}
