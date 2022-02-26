#include "Shape.h"


Shape::Shape() {
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
}

Shape::Shape(int a, int b, int c, int d) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

std::istream& operator >>(std::istream& in, Shape& shape) {
	std::cout << "Nhap cac canh tu giac: ";
	in >> shape.a >> shape.b >> shape.c >> shape.d;
	return in;
	/*
	int a = b = c = 10;
	khi khởi tạo biến và gán giá trị cho nó thì nó sẽ đi từ phải sang trái
	còn khi nhập giá trị(>>) thì nó sẽ đi từ trái sang phải
	*/
}

std::ostream& operator <<(std::ostream& out, Shape& shape) {
	out << "(" << shape.a << ", " << shape.b << ", " << shape.c << ", " << shape.d << ")";
	return out;
}

int Shape::operator*()
{
	return (this->a + this->b + this->c + this->d) / 2;
}

Shape Shape::operator+(const Shape& shape)
{
	Shape sum;
	sum.a = this->a + shape.a;
	sum.b = this->b + shape.b;
	sum.c = this->c + shape.c;
	sum.d = this->d + shape.d;
	return sum;
}

bool Shape::operator==(const Shape& shape)
{
	return (this->a + this->b + this->c + this->d) == (shape.a + shape.b + shape.c + shape.d);
}