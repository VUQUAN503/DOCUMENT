#pragma once
#include <iostream>


class NhanVien
{
protected:
	std::string name;
	std::string address;
	std::string date;// day/month/year
public:
	NhanVien(const std::string& name, const std::string &address, const std::string &date) : name(name), address(address), date(date) {
	}
	std::string getName()
	{
		return this->name;
	}
	std::string getAddress()
	{
		return this->address;
	}
	std::string getDate()
	{
		return this->date;
	}
	double tinhLuong()
	{
		// không viết code được trong đây
		return 0;
	}
};

