#pragma once
#include "Rectangle.h"

// quy tắc kế thừa dùng dấu : trước tên class con và tiếp theo lả từ khóa dẫn xuât(public, private, protected)
// tên class cơ sở(class cha)
class Square : public Rectangle
{
private:
	double edge;
public:
	Square(double edge, const std::string& color, double border);
};

