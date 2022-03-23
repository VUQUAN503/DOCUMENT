#pragma once
#include "ChiTiet.h"
#include "ChiTietDon.h"
#include "ChiTietPhuc.h"

class May
{
private:
	std::vector<ChiTiet*> listCT;
	int soLuongCTMay;
public:
	void Nhap();
	void Xuat();
	/*
	void TinhGiaTri();
	ChiTiet* TimKiemCTTheoMaSo(const std::string& maSo);
	int DemSoLuongCT();*/
};

