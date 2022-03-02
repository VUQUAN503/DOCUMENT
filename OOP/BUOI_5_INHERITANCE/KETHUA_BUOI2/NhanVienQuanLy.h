#pragma once
#include "NhanVien.h"

class NhanVienQuanLy : public NhanVien
{
private:
	double luongCoBan;
	double heSoLuong;
public:
	NhanVienQuanLy(const std::string& name, const std::string& address, const std::string& date, double luongCoBan, double heSoLuong)
		: NhanVien(name, address, date) {
		this->luongCoBan = luongCoBan;
		this->heSoLuong = heSoLuong;
	}

	double tinhLuong() {
		return this->luongCoBan * this->heSoLuong;
	}
};

