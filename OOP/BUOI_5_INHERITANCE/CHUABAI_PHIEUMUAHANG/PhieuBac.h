#pragma once
#include "PhieuVang.h"

class PhieuBac : public PhieuMuaHang
{
public:

	void Nhap()
	{
		PhieuMuaHang::Nhap();
	}

	/*PhieuBac(const std::string& ma, KhachHangThuongXuyen khTX, KhachHangVip khV, int loaiKhachHang, Ngay ngayHetHan)
		: PhieuMuaHang(ma, khTX, khV, loaiKhachHang, ngayHetHan) {}*/
	float tinhGiaTri()
	{
		// điểm khách hàng nhân với 10000
		return this->loaiKhachHang == 0 ? this->khTX.tinhDiem() * 15000 : this->khV.tinhDiem() * 15000;
	}
};
