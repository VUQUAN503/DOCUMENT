#pragma once
#include "KhachHangThuongXuyen.h"
// kế thừa từ class Khách Hàng
class KhachHangVip : public KhachHang
{
private:
	int soTienDaMuaHang;
public:
	/*KhachHangVip(const std::string& ma, const std::string& hoTen, ThongTinLienLac lh, Ngay ngaySinh, int soTienDaMuaHang)
		: KhachHang(ma, hoTen, lh, ngaySinh) {
		this->soTienDaMuaHang = soTienDaMuaHang;
	}*/

	void Nhap()
	{
		KhachHang::Nhap();
		PrintUTF8::print(L"Nhập số tiền đã mua hàng: ");
		std::cin >> this->soTienDaMuaHang;
	}

	void Xuat()
	{
		KhachHang::Xuat();
		std::cout << "So tien da mua: " << this->soTienDaMuaHang << std::endl;
	}
	
	float tinhDiem()
	{
		return (float)this->soTienDaMuaHang / 100000;
	}
};

