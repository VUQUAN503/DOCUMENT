#pragma once
#include "ChiTiet.h"

class ChiTietDon : public ChiTiet
{
private:
	double giaTien;
public:
	void Nhap();
	void Xuat();
	/*void TinhTien();
	ChiTiet* TimKiemCTTheoMaSo(const std::string& maSo);
	int DemSoLuongCT();*/
};

