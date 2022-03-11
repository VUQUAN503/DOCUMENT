#pragma once
#include "ThongTinLienLac.h"

class KhachHang
{
protected:
	std::string ma, hoTen;
	ThongTinLienLac lh;
	Ngay ngaySinh;
public:
	/*KhachHang(const std::string &ma, const std::string &hoTen, ThongTinLienLac lh, Ngay ngaySinh)
		: ma(ma), hoTen(hoTen), lh(lh), ngaySinh(ngaySinh) {}*/
	void Nhap()
	{
		std::cin.ignore();
		PrintUTF8::print(L"Nhập mã số khách hàng: ");
		std::getline(std::cin, this->ma);

		PrintUTF8::print(L"Nhập tên khách hàng: ");
		std::getline(std::cin, this->hoTen);

		this->lh.Nhap();

		this->ngaySinh.Nhap();
	}
	void Xuat()
	{
		std::cout << "Ma: " << this->ma << std::endl;
		std::cout << "Ho Ten: " << this->hoTen << std::endl;
		this->lh.Xuat();// gọi hàm xuất của class Thong tin lien lac
		this->ngaySinh.Xuat();
	}
};

