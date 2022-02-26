#include "Disk.h"

double Disk::PI = 3.14;

Disk::Disk(double radius, const std::string& color, double border)
	: radius(radius), color(color), border(border)
{}

double Disk::getArea() {
	return Disk::PI * this->radius * this->radius;
}

void Disk::paint() {
	printf("|DISK      |%-4.1f|    |%-10s|%4.1f|\n", this->radius, this->color.c_str(), this->border);
}