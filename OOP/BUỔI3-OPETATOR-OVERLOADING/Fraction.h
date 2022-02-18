#pragma once
#include <iostream>

// 1/2
class Fraction
{
private:
	int tuSo, mauSo;
public:
	Fraction(int tuso, int mauso);// hàm khởi tạo 2 tham số
	void Xuat();
	// tổng 2 số thực => float, double
	// tổng của hai số nguyên => int
	// phương thức tổng 2 phân số => hàm này nó sẽ trả về 1 phân số
	Fraction Sum(const Fraction &);
	Fraction operator +(const Fraction&);
	Fraction operator -(const Fraction&);
	Fraction operator *(const Fraction&);
	Fraction operator /(const Fraction&);
	Fraction& operator ++();
	Fraction& operator ++(int x);
	Fraction& operator +=(const Fraction& );
	friend std::ostream& operator<< (std::ostream&, Fraction &);
};

