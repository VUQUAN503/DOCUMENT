#pragma once
#include "PhieuMuaHang.h"

class PhieuVang : public PhieuMuaHang
{
public:
	void Nhap()
	{
		PhieuMuaHang::Nhap();
	}
	/*PhieuVang(const std::string& ma, KhachHangThuongXuyen khTX, KhachHangVip khV, int loaiKhachHang, Ngay ngayHetHan)
		: PhieuMuaHang(ma, khTX, khV, loaiKhachHang, ngayHetHan) {}*/
	float tinhGiaTri()
	{
		// điểm khách hàng nhân với 10000
		if (this->loaiKhachHang == 0)
		{
			// khách hàng thường xuyên
			if (this->khTX.tinhDiem() < 200) return this->khTX.tinhDiem() * 25000;
			return this->khTX.tinhDiem() * 40000;
		}
		else {
			if (this->khTX.tinhDiem() < 200) return this->khTX.tinhDiem() * 25000;
			return this->khTX.tinhDiem() * 40000;
		}
		return 0;
	}
};
