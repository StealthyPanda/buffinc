#include "../inc/color.h"

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

color color::rgb(char r, char g, char b)
{
	color c;
	c.r = r;
	c.g = g;
	c.b = b;
	return c;
}

color color::hsv(char h, char s, char v)
{
	color c;
	c.h = h;
	c.s = s;
	c.v = v;
	return c;
}

color rgb(char r, char g, char b)
{
	return color::rgb(r, g, b);
}

color hsv(char h, char s, char v)
{
	return color::hsv(h, s, v);
}