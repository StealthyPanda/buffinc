#include "renderer.h"
#ifndef CMATH
#include <cmath>
#define CMATH
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

buffinc::World::World()
{
	this->globalx = *(new Vector3(1, 0, 0));
	this->globaly = *(new Vector3(0, 1, 0));
	this->globalz = *(new Vector3(0, 0, 1));
}



buffinc::Shell::Shell()
{

}

buffinc::Shell::Shell(Vector3 vertices[], int nvertices)
{
	this->vertices = vertices;
	this->nvertices = nvertices;
}

Vector3 buffinc::Plane::getNormal()
{
	return crossproduct((vertices[1] - vertices[0]), (vertices[2] - vertices[0])).getNormalised();
}

long double buffinc::Plane::getArea()
{
	if (nvertices == 3) return crossproduct((vertices[2] - vertices[0]), (vertices[1] - vertices[0])).getMagnitude();
	return (crossproduct((vertices[2] - vertices[0]), (vertices[1] - vertices[0])).getMagnitude()
			+
			crossproduct((vertices[3] - vertices[0]), (vertices[2] - vertices[0])).getMagnitude());
}


buffinc::Plane::Plane()
{
	this->exists = false;
}

buffinc::Plane::Plane(Vector3 point, Vector3 normal)
{
	this->point = point;
	this->normal = normal;
	this->bounded = false;
	this->exists = true;
}



buffinc::Plane::Plane(Vector3* vertices, int nvertices)
{
	if (!((nvertices==3) or (nvertices == 4))) return;
	Vector3 abccross = crossproduct((vertices[2] - vertices[0]), (vertices[1] - vertices[0])).getNormalised();
	if (nvertices == 4)
	{
		Vector3 acdcross = crossproduct((vertices[3] - vertices[0]), (vertices[2] - vertices[0])).getNormalised();
		if (!(abccross == acdcross)) return;
	}

	Vector3 point = vertices[0] + vertices[1] + vertices[2];

	if (nvertices == 4)
	{
		point = point + vertices[3];
		point = (point * 0.25);
	}
	else point = point * (1/3);

	this->vertices = vertices;
	this->nvertices = nvertices;
	this->bounded = true;
	this->normal = (abccross * -1);
	this->point = point;
	this->exists = true;
}

void buffinc::Plane::rotateglobal(long double radians, Vector3 axis)
{
	for (int i = 0; i < this->nvertices; i++)
	{
		this->vertices[i] = getRotated(this->vertices, radians, axis);
	}
	this->normal = this->getNormal();
}

void buffinc::Plane::rotateglobal(Quaternion rotor)
{
	for (int i = 0; i < this->nvertices; i++)
	{
		this->vertices[i] = getRotated(this->vertices, rotor);
	}
	this->normal = this->getNormal();
}

void buffinc::Plane::display()
{
	std::cout << "Points : " << std::endl;
	for (int i = 0; i < this->nvertices; i++) std::cout << this->vertices[i] << std::endl;
	std::cout << "Center  : " << this->point << std::endl;
	std::cout << "Normal  : " << this->normal << std::endl;
	std::cout << "Exists  : " << this->exists << std::endl;
	std::cout << "Bounded : " << this->bounded << std::endl;
}


buffinc::Ray::Ray()
{

}

buffinc::Ray::Ray(Vector3 start, Vector3 direction)
{
	this->start = start;
	this->direction = direction;
}

buffinc::Ray* buffinc::Ray::getRay(Vector3 startpoint, Vector3 endpoint)
{
	return new Ray(startpoint, (endpoint - startpoint).getNormalised());
}

std::ostream& operator << (std::ostream& outstream, buffinc::Ray ray)
{
	outstream << ray.start << "-->" << ray.direction;
	return outstream;
}

//outputs plane's postion;normal vectors;bounded;exists
std::ostream& operator << (std::ostream& outstream, buffinc::Plane plane)
{
	outstream << "[" << plane.point << ";" << plane.normal << ";"
					<< plane.bounded << ";" << plane.exists << "]";
	return outstream; 
}

Vector3& operator << (buffinc::Plane& plane, buffinc::Ray& ray)
{

	long double lambda = (dotproduct( (plane.point - ray.start), plane.normal )/dotproduct(ray.direction, plane.normal));
	static Vector3 intersection = (ray.start + (lambda * ray.direction));
	if (lambda < 0) 
	{
		intersection.isnull = true;
		return intersection;
	}
	if (!plane.bounded) return intersection;


	//todo: somehow optimise this part; it is incredibly expensive for something that shouldn't be:
	long double area1 = crossproduct((plane.vertices[0] - intersection), (plane.vertices[1] - intersection)).getMagnitude();
	long double area2 = crossproduct((plane.vertices[1] - intersection), (plane.vertices[2] - intersection)).getMagnitude();
	long double area3 = crossproduct((plane.vertices[2] - intersection), (plane.vertices[3] - intersection)).getMagnitude();
	long double area4 = crossproduct((plane.vertices[3] - intersection), (plane.vertices[0] - intersection)).getMagnitude();

	if (((area1 + area2 + area3 + area4) - plane.getArea()) > PLANETHRESH) intersection.isnull = true;

	return intersection;
}

Vector3& operator >> (buffinc::Ray& ray, buffinc::Plane& plane)
{
	return (plane << ray);
}