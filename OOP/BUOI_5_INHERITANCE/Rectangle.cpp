#include "Rectangle.h"

Rectangle::Rectangle(double width, double length, const std::string& color, double border)
	: width(width), length(length), color(color), border(border)
{}

double Rectangle::getArea() {
	return this->width * this->length;
}

void Rectangle::paint() {
	printf("|Rectangle |%-4.1f|%-4.1f|%-10s|%-4.1f|\n", this->width, this->length, this->color.c_str(), this->border);
}