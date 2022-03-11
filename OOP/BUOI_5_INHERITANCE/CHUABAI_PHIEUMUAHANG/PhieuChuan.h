#pragma once
#include "PhieuBac.h"

class PhieuChuan : public PhieuMuaHang
{
public:

	void Nhap()
	{
		PhieuMuaHang::Nhap();
	}

	/*PhieuChuan(const std::string& ma, KhachHangThuongXuyen khTX, KhachHangVip khV, int loaiKhachHang, Ngay ngayHetHan)
		: PhieuMuaHang(ma, khTX, khV, loaiKhachHang, ngayHetHan){}*/
	
	float tinhGiaTri()
	{
		// điểm khách hàng nhân với 10000
		return this->loaiKhachHang == 0 ? this->khTX.tinhDiem() * 10000 : this->khV.tinhDiem() * 10000;
	}
};

