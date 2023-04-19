#include <iostream>

#include "./inc/camera.h"

#define pi 3.141592

int main()
{
	using namespace std;
	cout << "Hajimemashite" << endl;
	
	camera cam;

	for (int i = 0; i < 10; ++i)
	{
	 	cam.capture();
	}


	return 0;
}