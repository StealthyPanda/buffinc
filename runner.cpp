#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#include "consolidatetest.h"
//these 2 statements give you access to math constants like M_PI (pi), M_PI_2 (pi/2), M_PI/4 (pi/4) etc
#define _USE_MATH_DEFINES
#include <cmath>

//#include <sstream>

//#include "CImg.h"
//using namespace std;
//using namespace cimg_library;

/*int main()
{
	cimg_library::CImg<unsigned char> image("C:\\Users\\StealthyPanda\\Desktop\\er.png");
	cimg_library::CImgDisplay display(image, "BRUH");
	
	return 0;
}*/

//g++ compile command for this thing
//g++ runner.cpp ... * all your cpp files * -o builds/rerun -std=c++11 -lgdi32

/*int main()
{

	cimg_library::CImg<unsigned char> animage = cimg_library::CImg<unsigned char>(640, 300, 1, 3);
	animage.fill(0);
	unsigned char lecolor[] = {120, 255, 120};
	//animage.draw_text(150, 100, "HELLO WORLD", lecolor);
	//animage.display("BRUH");
	int index = 0;

	for (long int i = 0; i < (640 * 300); ++i)
	{
		/*if (animage[i] && index < 21)
		{
			index++;
			std::cout << animage << std::endl;
			//std::cout << "[" << animage[i][0] << ", " << animage[i][1] << ", " << animage[i][2] << std::endl;
		}
		std::cout << animage[i] << std::endl;
	}

	return 0;
}
*/



int main()
{

	
	Vector3 pointer = Vector3(1, 0, 0);

	//std::cout << getRotated(pointer, M_PI_2, Vector3(1, 0, 0)).getFiltered() << std::endl;

	rotate(pointer, M_PI, Vector3(0, 0, 1));

	pointer.filter();

	std::cout << "Original: " << pointer << std::endl;

	return 0;
}

/*
int main(int argc, char const *argv[])
{
	int counter = 0;
	for (int i = 0; i < argc; ++i)
	{
		std::stringstream ss(argv[i]);
		int x;
		ss >> x;
		counter += x;
	}
	std::cout << counter << std::endl;
	//system("mkdir encore");
	return 0;
}*/

