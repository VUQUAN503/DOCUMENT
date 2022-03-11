#pragma once
#include "PhieuChuan.h"
#include <vector>

class CongTy
{
private:
	std::vector<PhieuBac> listPhieuBac;
	std::vector<PhieuChuan> listPhieuChuan;
	std::vector<PhieuVang> listPhieuVang;
public:
	
	void Menu()
	{
		while (true)
		{
			PrintUTF8::print(L"1.0 Nhập vào danh sách phiêu\n");
			PrintUTF8::print(L"2.0 In danh sách phiếu có trong công ty\n");
			PrintUTF8::print(L"3.0 Tìm và in ra màn hình các phiếu mua hàng có giá trị nằm trong khoảng cho trước\n");
			PrintUTF8::print(L"4.0 Thoát\n");
			int luachon;
			PrintUTF8::print(L"Nhập vào lựa chọn của bạn: ");
			std::cin >> luachon;
			PhieuChuan phieuChuan;
			PhieuBac phieuBac;
			PhieuVang phieuVang;
			int i = 0;
			if (luachon == 1) {
				// nhập vào danh sách phiếu mua hàng nếu người dùng chọn c(Nhập phiếu chuẩn, b là phiếu bạc, v là phiếu vàng)
				char phieu;
				PrintUTF8::print(L"Nhập loại phiếu bạn muốn nhập(c: Phiếu Chuẩn, b: Phiếu Bạc, v : Phiếu Vàng): ");
				std::cin >> phieu;
				switch (phieu)
				{
				case 'c':
					phieuChuan.Nhap();
					this->listPhieuChuan.push_back(phieuChuan);
					break;
				case 'b':
					phieuBac.Nhap();
					this->listPhieuBac.push_back(phieuBac);
					break;
				case 'v':
					phieuVang.Nhap();
					this->listPhieuVang.push_back(phieuVang);
					break;
				default:
					break;
				}
				PrintUTF8::print(L"Ấn enter để tiếp tục");
				std::cin.ignore();
				std::cin.get();// dừng màn hình xem kết quả
				system("cls");
			}
			else if (luachon == 2)
			{
				PrintUTF8::print(L"Danh sách phiếu có trong công ty la: \n");
				for (int i = 0; i < this->listPhieuChuan.size(); ++i)
					this->listPhieuChuan[i].Xuat();
				for (int i = 0; i < this->listPhieuBac.size(); ++i)
					this->listPhieuBac[i].Xuat();
				for (int i = 0; i < this->listPhieuVang.size(); ++i)
					this->listPhieuVang[i].Xuat();

				PrintUTF8::print(L"Ấn enter để tiếp tục!");
				Sleep(1000);
				std::cin.ignore();
				std::cin.get();// dừng màn hình xem kết quả
				system("cls");
			}
			else if (luachon == 3)
			{
				//3.0 Tìm và in ra màn hình các phiếu mua hàng có giá trị nằm trong khoang cho truoc
				// nhập vào khoảng x, y cho trước
				int x, y;
				PrintUTF8::print(L"Nhập vào khoảng giá trị cần tìm: ");
				std::cin >> x >> y;

				for (int i = 0; i < this->listPhieuChuan.size(); ++i)
					if (this->listPhieuChuan[i].tinhGiaTri() >= x && this->listPhieuChuan[i].tinhGiaTri() <= y)
						this->listPhieuChuan[i].Xuat();
				for (int i = 0; i < this->listPhieuBac.size(); ++i)
					if (this->listPhieuBac[i].tinhGiaTri() >= x && this->listPhieuBac[i].tinhGiaTri() <= y)
						this->listPhieuBac[i].Xuat();
				for (int i = 0; i < this->listPhieuVang.size(); ++i)
					if (this->listPhieuVang[i].tinhGiaTri() >= x && this->listPhieuVang[i].tinhGiaTri() <= y)
						this->listPhieuVang[i].Xuat();
				PrintUTF8::print(L"Ấn enter để tiếp tục");
				Sleep(1000);
				std::cin.ignore();
				std::cin.get();// dừng màn hình xem kết quả
				system("cls");
			}
			else if (luachon == 4)
			{
				PrintUTF8::print(L"Đã Thoát");
				break;
			}
			else {
				PrintUTF8::print(L"Vui lòng nhập lựa chọn trong khoảng từ 1 đến 3");
				system("cls");// xóa màn hình
			}
		}
	}
};

