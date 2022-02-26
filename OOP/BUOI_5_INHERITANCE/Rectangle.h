#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>

class Rectangle
{
protected:
	double width;
	double length;
	std::string color;
	double border;
public:
	Rectangle(double width, double length, const std::string& color, double border);
	double getArea();
	void paint();
};

