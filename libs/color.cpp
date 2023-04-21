#include "../inc/color.h"
#include <iostream>

color::color()
{
	r = 0;
	g = 0;
	b = 0;
	h = 0;
	s = 0;
	v = 0;
}

color::~color()
{
}

color::color(const color& c)
{
	r = c.r;
	g = c.g;
	b = c.b;
	h = c.h;
	s = c.s;
	v = c.v;
}

//formulas:
//https://www.rapidtables.com/convert/color/rgb-to-hsv.html
color color::rgb(unsigned char r, unsigned char g, unsigned char b)
{
	color c;
	c.r = r;
	c.g = g;
	c.b = b;

	std::cout << "r: " << short(r) << " g: " << short(g) << " b: " << short(b) << std::endl;

	double rdash = ((short) r)/255.0, gdash = ((short) g)/255.0, bdash = ((short) b)/255.0;
	double cmax = rdash, cmin = rdash;

	if (gdash > cmax) cmax = gdash;
	if (bdash > cmax) cmax = bdash;

	if (gdash < cmin) cmin = gdash;
	if (bdash < cmin) cmin = bdash;

	std::cout << "rdash : " << rdash << " gdash: " << gdash << " bdash: " << bdash << std::endl;

	double delta = cmax - cmin;

	double h, s, v, buffer;

	if (delta == 0) h = 0;
	else if (cmax == rdash)
	{
		buffer = ((gdash - bdash)/delta);
		h = 60 * ((int)(buffer) % 6);
		h += (buffer - (int)(buffer));
	}
	else if (cmax == gdash)
		h = 60 * (((bdash - rdash)/delta) + 2);
	else if (cmax == bdash)
		h = 60 * (((rdash - gdash)/delta) + 4);

	if (cmax == 0)
		s = 0;
	else s = delta/cmax;

	v = cmax;

	c.h = h;
	c.s = s;
	c.v = v;

	return c;
}

//formulas are straight up copied from here:
//https://www.rapidtables.com/convert/color/hsv-to-rgb.html
color color::hsv(double h, double s, double v)
{
	color c;
	c.h = h;
	c.s = s;
	c.v = v;

	double C = v * s, m = v - C;

	double X = h/60.0;

	X = (((int) X) % 2) + (X - (int)(X)) - 1;
	if (X < 0) X = -X;

	X = C * (1 - X);


	double rdash, gdash, bdash;

	if (h < 60)
	{
		rdash = C;
		gdash = X;
		bdash = 0;
	}
	else if (h < 120)
	{
		rdash = X;
		gdash = C;
		bdash = 0;
	}
	else if (h < 180)
	{
		rdash = 0;
		gdash = C;
		bdash = X;
	}
	else if (h < 240)
	{
		rdash = 0;
		gdash = X;
		bdash = C;
	}
	else if (h < 300)
	{
		rdash = X;
		gdash = 0;
		bdash = C;
	}
	else if (h < 360)
	{
		rdash = C;
		gdash = 0;
		bdash = X;
	}

	std::cout << "In hsv: " << m << std::endl;
	std::cout << rdash << " " << gdash << " " << bdash << std::endl;

	c.r = (rdash + m) * 255;
	c.g = (gdash + m) * 255;
	c.b = (bdash + m) * 255;

	return c;
}

color rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return color::rgb(r, g, b);
}

color hsv(double h, double s, double v)
{
	return color::hsv(h, s, v);
}