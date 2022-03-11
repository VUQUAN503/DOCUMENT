#pragma once
#include "KhachHang.h"

class KhachHangThuongXuyen : public KhachHang
{
private:
	Ngay ngayThamGia;
public:
	
	/*KhachHangThuongXuyen(const std::string& ma, const std::string& hoTen, ThongTinLienLac lh, Ngay ngaySinh, Ngay ngayThamGia)
		: KhachHang(ma, hoTen, lh, ngaySinh)
	{
		this->ngayThamGia = ngayThamGia;
	}*/
	void Nhap()
	{
		KhachHang::Nhap();
		this->ngayThamGia.Nhap();
	}

	void Xuat()
	{
		KhachHang::Xuat();
		this->ngayThamGia.Xuat();
	}

	float tinhDiem()
	{
		// số năm tham gia(năm hiện tại - năm tham gia) nhân với 10;
		return (float)(2022 - this->ngayThamGia.getNam()) * 10.0f;
	}
};

