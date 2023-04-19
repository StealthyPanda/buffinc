#pragma once

class color
{
public:
	char r, g, b, h, s, v;
	color();
	~color();
	color(const color& c);

	static color rgb(char r, char g, char b);
	static color hsv(char r, char g, char b);
};

color rgb(char r, char g, char b);
color hsv(char h, char s, char v);