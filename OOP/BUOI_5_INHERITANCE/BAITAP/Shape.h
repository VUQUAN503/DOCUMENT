#pragma once
#include <iostream>

class Shape
{
private:
	int a, b, c, d;
public:
	Shape();
	Shape(int , int , int , int );
	friend std::istream& operator >>(std::istream& , Shape&);
	friend std::ostream& operator <<(std::ostream& , Shape&);
	// toán tử nhân là trả về nửa chu vi
	int operator *();
	Shape operator +(const Shape&);
	bool operator ==(const Shape&);
};

