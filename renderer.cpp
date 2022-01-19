#include "renderer.h"
#include <cmath>
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
	return crossproduct((vertices[2] - vertices[0]), (vertices[1] - vertices[0])).getNormalised();
}


buffinc::Plane::Plane()
{

}

buffinc::Plane::Plane(Vector3 point, Vector3 normal)
{
	this->point = point;
	this->normal = normal;
	this->bounded = false;
}



buffinc::Plane::Plane(Vector3 vertices[], int nvertices)
{
	if (!((nvertices==3) or (nvertices == 4))) return;
	Vector3 abccross = crossproduct((vertices[2] - vertices[0]), (vertices[1] - vertices[0])).getNormalised();
	if (nvertices == 4)
	{
		Vector3 acdcross = crossproduct((vertices[3] - vertices[0]), (vertices[2] - vertices[0])).getNormalised();
		if (!(abccross == acdcross)) return;
	}
	this->vertices = vertices;
	this->nvertices = nvertices;
	this->bounded = true;
	this->normal = abccross;
}