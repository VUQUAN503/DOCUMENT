#include "Fraction.h"

Fraction::Fraction(int tuSo, int mauSo)
{
	this->tuSo = tuSo;
	this->mauSo = mauSo;
}

// tuso/mauso
void Fraction::Xuat() {
	std::cout << this->tuSo << "/" << this->mauSo << std::endl;
}

Fraction Fraction::Sum(const Fraction &fraction) {
	// quy đồng
	Fraction temp((this->tuSo * fraction.mauSo + this->mauSo * fraction.tuSo), (this->mauSo * fraction.mauSo));
	return temp;
}

Fraction Fraction::operator+(const Fraction& fraction)
{
	Fraction temp((this->tuSo * fraction.mauSo + this->mauSo * fraction.tuSo), (this->mauSo * fraction.mauSo));
	return temp;
}

Fraction Fraction::operator-(const Fraction& fraction)
{
	Fraction temp((this->tuSo * fraction.mauSo - this->mauSo * fraction.tuSo), (this->mauSo * fraction.mauSo));
	if (temp.tuSo == 0) temp.mauSo = 0;
	return temp;
}

Fraction Fraction::operator*(const Fraction& fraction)
{
	Fraction temp((this->tuSo * fraction.tuSo), (this->mauSo * fraction.mauSo));
	return temp;
}

Fraction Fraction::operator/(const Fraction& fraction)
{
	return Fraction((this->tuSo * fraction.mauSo), (this->mauSo * fraction.tuSo));
}

Fraction& Fraction::operator++()
{
	this->tuSo = this->tuSo + this->mauSo;
	// tiền tố ++a => tăng trước rồi gán
	return *(this);
}

Fraction& Fraction::operator++(int x)
{
	// gán trước rồi mới tăng
	// int c = 5++ => c = 5
	Fraction temp = *this;// gán cho tem
	this->tuSo = this->tuSo + this->mauSo;// chính this tăng lên 1
	return temp;
}

Fraction& Fraction::operator+=(const Fraction &fraction)
{
	this->tuSo = this->tuSo * fraction.mauSo + this->mauSo * fraction.tuSo;
	this->mauSo = this->mauSo * this->mauSo;
	return *(this);
}

std::ostream& operator<<(std::ostream& out, Fraction & fraction)
{
	out << fraction.tuSo << "/" << fraction.mauSo;
	return out;
}