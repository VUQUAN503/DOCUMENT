#include "May.h"


void May::Nhap()
{
	std::cout << "Nhap so luong chi tiet cua may: ";
	std::cin >> this->soLuongCTMay;

	for (int i = 0; i < this->soLuongCTMay; ++i)
	{
		// làm thế nào biết đc nó là chi tiết dơn hay chi tiết phức
		int luaChon = 0;
		do
		{
			std::cout << "Moi ban chon chi tiet thanh phan la chi tiet don hay chi tiet phuc (0.don, 1.phuc): ";
			std::cin >> luaChon;
		} while (luaChon != 0 && luaChon != 1);
		ChiTiet* chiTiet = NULL;
		if (luaChon == 0)
			chiTiet = new ChiTietDon();
		else if (luaChon == 1)
			chiTiet = new ChiTietPhuc();
		chiTiet->Nhap();
		listCT.push_back(chiTiet);
	}
}

void May::Xuat()
{
	std::cout << "So luong chi tiet thanh phan cua may: " << this->soLuongCTMay << std::endl;
	for (int i = 0; i < this->listCT.size(); ++i)
		this->listCT[i]->Xuat();
}