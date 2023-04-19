#include "../inc/raster.h"

#include <iostream>
#include <fstream>

using namespace std;

raster::raster(unsigned r, unsigned c)
{
	rows = r;
	cols = c;

	matrix = new char**[rows];
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new char*[cols];
		for (int j = 0; j < cols; ++j)
		{
			matrix[i][j] = new char[3];
			for (int k = 0; k < 3; ++k)
			{
				matrix[i][j][k] = 0;
			}
		}
	}
}

raster::raster()
{
	matrix = NULL;
	rows = 0;
	cols = 0;
}

raster::~raster()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			delete[] matrix[i][j];
		}
		delete[] matrix[i];
	}
	delete[] matrix;
}

void raster::writetofile(const char* filename)
{
	ofstream file { filename };
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			file << (int) matrix[i][j][0] << ",";
			file << (int) matrix[i][j][1] << ",";
			file << (int) matrix[i][j][2];
			if (j < (cols - 1)) file << "|";
		}
		if (i < (rows - 1)) file << "\n";
	}
}

void raster::writetofile(std::string filename)
{
	ofstream file { filename };
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			file << (int) matrix[i][j][0] << ",";
			file << (int) matrix[i][j][1] << ",";
			file << (int) matrix[i][j][2];
			if (j < (cols - 1)) file << "|";
		}
		if (i < (rows - 1)) file << "\n";
	}
}