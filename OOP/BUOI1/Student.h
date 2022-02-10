#pragma once
#include <iostream>

class Student
{
private:
	std::string rollNo;
	std::string name;
	int age;
public:
	Student() { std::cout << "Doi tuong thuoc class Student vua duoc khoi tao!" << std::endl; };
	Student(std::string name) {
		std::cout << "Ham khoi tao voi 1 tham so la: " << name << std::endl;
		this->name = name;
		// name là thuộc tính của đối tượng gọi hàm khởi tạo 1 tham số
		// this-> chính đối tượng gọi hàm khởi tạo 1 tham số
	};
};


