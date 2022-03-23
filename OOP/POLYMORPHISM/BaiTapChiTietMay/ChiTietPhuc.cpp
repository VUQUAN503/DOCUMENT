#include "ChiTietPhuc.h"


void ChiTietPhuc::Nhap() {
	fflush(stdin);
	std::cout << "Nhap ma so chi tiet phuc: ";
	std::cin.ignore();
	std::getline(std::cin, this->maChiTiet);

	std::cout << "Nhap so luong chi tiet thanh phan: ";
	std::cin >> this->soLuongCTTP;

	// nhập danh sách chi tiết thành phần của chi tiết phức
	// chi tiết thành phần có thể là chi tiết đơn hoặc là chi tiết phức
	for (int i = 0; i < this->soLuongCTTP; ++i)
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

void ChiTietPhuc::Xuat()
{
	// implement(triển khai)
	std::cout << "Ma so chi tiet phuc: " << this->maChiTiet << std::endl;

	std::cout << "So chi tiet thanh phan: " << this->soLuongCTTP << std::endl;

	for (int i = 0; i < this->listCT.size(); ++i)
		this->listCT[i]->Xuat();
}

