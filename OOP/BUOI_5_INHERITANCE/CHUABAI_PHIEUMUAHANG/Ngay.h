#pragma once
#include "PrintUTF8.h"

class Ngay
{
private:
	int ngay, thang, nam;
public:
	void Nhap()
	{
		PrintUTF8::print(L"Nhập vào ngày tháng năm: ");
		std::cin >> this->ngay >> this->thang >> this->nam;
	}
	void Xuat()
	{
		std::cout << this->ngay << "/" << this->thang << "/" << this->nam << std::endl;
	}
	int getNam()
	{
		return this->nam;
	}
};

