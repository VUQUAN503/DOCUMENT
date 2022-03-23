#pragma once
#include "ChiTiet.h"
#include "ChiTietDon.h"

class ChiTietPhuc : public ChiTiet
{
private:
	int soLuongCTTP;
	std::vector<ChiTiet*> listCT;
public:
	void Nhap();
	void Xuat();
	/*void TinhTien();
	ChiTiet* TimKiemCTTheoMaSo(const std::string& maSo);
	int DemSoLuongCT();*/
};

