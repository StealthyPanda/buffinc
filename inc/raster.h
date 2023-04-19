#pragma once

#include <string>

class raster
{
public:
	unsigned rows, cols;

	char ***matrix;

	raster(unsigned, unsigned);
	raster();
	~raster();
	
	void writetofile(const char*);
	void writetofile(std::string str);
};