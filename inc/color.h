#pragma once

class color
{
public:
	unsigned char r, g, b;
	double h, s, v;
	
	color();
	~color();
	color(const color& c);

	static color rgb(unsigned char r, unsigned char g, unsigned char b);
	static color hsv(double h, double s, double v);
};

color rgb(unsigned char r, unsigned char g, unsigned char b);
color hsv(double h, double s, double v);