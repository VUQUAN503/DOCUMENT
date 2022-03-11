#pragma once
#include "Ngay.h"

class ThongTinLienLac
{
private:
	std::string diaChi, dienThoai, email;
public:
	/*ThongTinLienLac(const std::string &diaChi, const std::string &dienThoai, const std::string &email)
		: diaChi(diaChi), dienThoai(dienThoai), email(email){}*/


	void Nhap()
	{
		PrintUTF8::print(L"Nhập vào địa chỉ: ");
		std::cin.ignore();
		std::getline(std::cin, this->diaChi);
		PrintUTF8::print(L"Nhập vào điện thoại: ");
		std::getline(std::cin, this->dienThoai);
		PrintUTF8::print(L"Nhập vào email: ");
		std::getline(std::cin, this->email);
	}
	void Xuat()
	{
		std::cout << "Dia chi: " << this->diaChi << std::endl;
		std::cout << "Dien Thoai: " << this->dienThoai << std::endl;
		std::cout << "Email: " << this->email << std::endl;
	}
};

