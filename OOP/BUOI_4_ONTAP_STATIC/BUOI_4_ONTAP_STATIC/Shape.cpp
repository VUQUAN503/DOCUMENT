#include "Shape.h"

Shape::Shape() {
	std::cout << "Default constructor" << std::endl;
	Shape::count++;
}

int Shape::count = 0;

Shape::Shape(float height, float R, float weight)
{
	Shape::count++;
	this->height = height;
	this->R = R;
	this->weight = weight;
}

std::ostream& operator <<(std::ostream& out, const Shape& shape) {
	out << "Shape(" << shape.height << ", " << shape.R << ", " << shape.weight << ")";
	return out;
}

std::istream& operator >>(std::istream& in, Shape &shape) {
	std::cout << "Nhap chieu cao: ";
	in >> shape.height;

	std::cout << "Nhap ban kinh: ";
	in >> shape.R;

	std::cout << "Nhap trong luong: ";
	in >> shape.weight;

	return in;
}

Shape Shape::operator +(const Shape& shape) {
	Shape sum;// hàm khởi tạo ngầm định
	if (this->R == shape.R)
	{
		sum.R = this->R;
		sum.height = this->height + shape.height;
		sum.weight = this->weight + shape.weight;
	}
	else {
		sum.R = 0;
		sum.weight = 0;
		sum.height = 0;
	}
	return sum;
}

float Shape::getArea()
{
	return 3.14 * this->R * this->R;
}

// SOILD
//S SINGLE RESPONSIBILITY PRINCIPLES
bool Shape::operator <(float number)
{
	if (this->getArea() < number) return true;
	return false;
}