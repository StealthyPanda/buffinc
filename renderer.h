#include "Vector3.h"
#include "Quaternion.h"

#define PLANETHRESH 0.00001

namespace buffinc
{

	class Plane
	{
	public:
		Vector3* vertices;
		Vector3 point, normal;
		int nvertices;
		bool bounded;

		Vector3 getNormal();

		Plane();
		Plane(Vector3 point, Vector3 normal);

		//vertices MUST be provided in cyclic order; otherwise expect weird behaviour
		Plane(Vector3 vertices[], int nvertices);
	};

	class Ray
	{
	public:
		Vector3 start, direction;

		Ray();
		Ray(Vector3 start, Vector3 direction);

		static Ray* getRay(Vector3 startpoint, Vector3 endpoint);
	};

	class Shell
	{
	public:
		Vector3* vertices;
		int nvertices;

		Shell();
		Shell(Vector3 vertices[], int nvertices);
	};

	class World
	{
	public:
		Vector3 globalx, globaly, globalz;

		World();
	};
}

std::ostream& operator << (std::ostream& outstream, buffinc::Ray ray);

Vector3 operator << (buffinc::Plane& plane, buffinc::Ray& ray);
Vector3 operator >> (buffinc::Ray& ray, buffinc::Plane& plane);