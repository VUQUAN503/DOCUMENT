#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>

class Disk
{
private:
	double radius;
	std::string color;
	double border;
public: static double PI;
public:
	Disk(double radius, const std::string& color, double border);
	double getArea();
	void paint();
};
