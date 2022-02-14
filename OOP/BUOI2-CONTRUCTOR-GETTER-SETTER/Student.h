#pragma once
#include <iostream>

// data access modify
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
		// name là thuộc tính của đối tượng đang gọi hàm khởi tạo 1 tham số
		// (con trỏ this)this-> chính đối tượng gọi hàm khởi tạo 1 tham số
	};
	Student(std::string name, std::string rollNo, int age) {
		std::cout << "ham khoi tao 3 tham so " << std::endl;
		this->name = name;
		this->rollNo = rollNo;
		(this->age) = age;
		// hàm khởi tạo 3 tham số
	};
	Student(const Student &student){
		std::cout << "Ham khoi tao sao chep" << std::endl;
		this->name = student.name;
		this->age = student.age;
		this->rollNo = student.rollNo;
	}
	// hàm huỷ
	~Student(){
		std::cout << "Doi tuong " << this->name << " da het pham vi su dung " << std::endl;
	}
	// trả về tên
	std::string getName() { return this->name; }
	std::string getRollNo() { return "liu liu"; }
	int getAge() { return this->age; }
	void setName(std::string name) { std::cout << "Ten khong duoc thay doi vi bo me da dat cho minh!\n"; }
};


