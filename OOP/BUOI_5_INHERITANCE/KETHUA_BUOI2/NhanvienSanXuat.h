#pragma once
#include "NhanVien.h"

class NhanvienSanXuat : public NhanVien
{
private:
	int soSanPham;
public:
	NhanvienSanXuat(const std::string& name, const std::string& address, const std::string& date, int soSanPham)
	 : NhanVien(name, address, date) {
		this->soSanPham = soSanPham;
	}
	double tinhLuong() {
		return this->soSanPham * 50000;
	}
};

