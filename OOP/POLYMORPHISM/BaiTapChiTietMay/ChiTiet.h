#pragma once
#include <iostream>
#include <vector>
#include <string>

class ChiTiet
{
protected:
	std::string maChiTiet;
public:
	virtual void Nhap();
	virtual void Xuat();
	/*virtual void TinhTien();
	virtual ChiTiet * TimKiemCTTheoMaSo(const std::string& maSo);
	virtual int DemSoLuongCT();*/
};

