#include "Time.h"

// kiểu dữ liệu tên lớp :: tên phương thức
Time::Time() {
	std::cout << "Ham khoi tao mac dinh" << std::endl;
}

Time::Time(int year) {
	this->year = year;
}

Time::Time(int year, int month) {
	this->year = year;
	this->month = month;
}

Time::Time(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

Time::Time(const Time& time)
{
	this->year = time.year;
	this->month = time.month;
	this->day = time.day;
}

void Time::Xuat() {
	std::cout << this->day << "/" << this->month << "/" << this->year << std::endl;
}