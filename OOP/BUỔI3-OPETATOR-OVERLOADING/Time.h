#pragma once
#include <iostream>

class Time
{
private:
	int day, month, year;
public:
	Time();
	Time(int year);
	Time(int year,int month);
	Time(int year, int month, int day);
	Time(const Time &);
	void Xuat();
};

