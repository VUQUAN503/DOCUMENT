#pragma once
#include "NhanVien.h"

// đơn kế thừa với từ khóa dẫn xuất là public
class NhanVienCongNhat : public NhanVien
{
private:
	int soNgayCong;
public:
	NhanVienCongNhat(const std::string& name, const std::string& address, const std::string& date, int soNgayCong)
	 : NhanVien(name, address, date) {
		this->soNgayCong = soNgayCong;
	}

	double tinhLuong()
	{
		return this->soNgayCong * 120000;
	}
};

