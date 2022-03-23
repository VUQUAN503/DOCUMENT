#include "ChiTietDon.h"

void ChiTietDon::Nhap()
{
	std::cout << "Nhap ma so chi tiet don: ";
	std::cin.ignore();
	std::getline(std::cin, this->maChiTiet);

	std::cout << "Nhap gia tien: ";
	std::cin >> this->giaTien;
}

void ChiTietDon::Xuat() {
	std::cout << "Ma so chi tiet don: " << this->maChiTiet << std::endl;
	std::cout << "Gia tien chi tiet don: " << this->giaTien << std::endl;
}