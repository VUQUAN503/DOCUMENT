#pragma once
#include "KhachHangVip.h"

class PhieuMuaHang
{
protected:
	std::string ma;
	KhachHangThuongXuyen khTX;
	KhachHangVip khV;
	int loaiKhachHang;// nếu bằng 0 là khách hàng thường xuyên còn nếu = 1 là khách hàng vip
	Ngay ngayHetHan;
public:
	
	/*PhieuMuaHang(const std::string& ma, KhachHangThuongXuyen khTX, KhachHangVip khV, int loaiKhachHang, Ngay ngayHetHan)
		: ma(ma), khTX(khTX), khV(khV), loaiKhachHang(loaiKhachHang), ngayHetHan(ngayHetHan)
	{}*/

	void Nhap()
	{
		std::cin.ignore();
		PrintUTF8::print(L"Nhập mã số phiếu: ");
		std::getline(std::cin, this->ma);

		PrintUTF8::print(L"Nhập loại khách hàng (0: Khách hàng TX, 1: Khách hàng víp): ");
		std::cin >> this->loaiKhachHang;

		if (this->loaiKhachHang == 0) this->khTX.Nhap();
		else this->khV.Nhap();

		this->ngayHetHan.Nhap();
	}

	void Xuat()
	{
		std::cout << "Ma phieu: " << this->ma << std::endl;
		if (this->loaiKhachHang == 0) this->khTX.Xuat();
		else if (this->loaiKhachHang == 1) this->khV.Xuat();
		this->ngayHetHan.Xuat();
	}
};

