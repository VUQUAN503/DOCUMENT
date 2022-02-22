#pragma once
#include <iostream>

class Shape
{
public:
	static int count;// đếm số lượng object của class
private:
	float height;// biến static là biến của mọi đối tượng
	// tức là mọi đội tượng được tạo ra đều có giá trị height = giá trị
	// 
	float R;
	float weight;// non-static
public:
	Shape();
	Shape(float height, float R, float weight);
	friend std::ostream& operator <<(std::ostream& out, const Shape& shape);
	friend std::istream& operator >>(std::istream&, Shape&);
	Shape operator +(const Shape& shape);
	bool operator <(float );
	float getArea();
	float getHeight() { return this->height; }
	void setHeight(float height) { this->height = height; }
	static void print()
	{
		std::cout << Shape::count << std::endl;
	}
};

