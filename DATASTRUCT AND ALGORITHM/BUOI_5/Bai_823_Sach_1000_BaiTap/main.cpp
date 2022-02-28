#include "D:\MyLib\quan.h"

struct Birthday {
	int day, month, year;
};

struct Staff {
	std::string name;
	Birthday date;
	double salary;
	std::string gender;
};


void input(Staff& staff)
{
	fflush(stdin);
	std::cout << "Inut name: ";
	std::getline(std::cin, staff.name);

	std::cout << "Input date: ";
	std::cin >> staff.date.day >> staff.date.month >> staff.date.year;

	std::cout << "Input salary: ";
	std::cin >> staff.salary;

	fflush(stdin);
	std::cout << "Input gender: ";
	std::getline(std::cin, staff.gender);

}

void output(Staff staff)
{
	std::cout << "Name: " << staff.name << std::endl;
	std::cout << "Birthday: " << staff.date.day << "/" << staff.date.month << "/" << staff.date.year << std::endl;
	std::cout << "Salary: " << staff.salary << "$" << std::endl;
	std::cout << "Gender: " << staff.gender << std::endl;
}

//B1: Tạo cấu trúc phần tử của danh sách
struct Node {
	Staff data;
	Node* next;
};

// cấu hình danh sách liên kết
struct LinkedList {
	Node* head;
};

// khởi tạo danh sách ban đầu là rỗng
void init(LinkedList& l)
{
	l.head = NULL;// danh sách ban đầu rỗng
}

// Tạo một node 
Node* createNode(Staff staff)
{
	Node* node = new Node;
	if (node == NULL) return NULL;
	node->data = staff;
	node->next = NULL;
	return node;
}

// thêm một node vào đầu danh sách
void addNode(LinkedList& l, Staff staff)
{
	Node* node = createNode(staff);
	if (l.head == NULL) l.head = node;
	else {
		node->next = l.head;
		l.head = node;
	}
}

void print(LinkedList l)
{
	for (Node* p = l.head; p != NULL; p = p->next)
		output(p->data);
}

// giải phóng danh sách liên kết
void removeAll(LinkedList& l)
{
	while (l.head != NULL)
	{
		Node* node = l.head;
		l.head = l.head->next;
		delete node;
	}
}

// liệt kê nhân viên trên 40 tuổi
void NhanVienTren40Tuoi(LinkedList l)
{
	std::cout << "Thong tin nhan vien tren 40 tuoi: \n";
	for (Node* p = l.head; p != NULL; p = p->next)
		if (2022 - p->data.date.year > 40)
			output(p->data);
}

// đếm số lượng nhân viên có lương trên 50$
int SoLuongNhanVienCoLuongTren50Do(LinkedList l)
{
	int count = 0;
	for (Node* p = l.head; p != NULL; p = p->next)
		if (p->data.salary > 50)
			count++;
	return count;
}


void sort(LinkedList l)
{
	for (Node* p = l.head; p != NULL; p = p->next)
	{
		for (Node* k = p->next; k != NULL; k = k->next)
		{
			if (p->data.date.year < k->data.date.year)
			{
				Staff tem = p->data;
				p->data = k->data;
				k->data = tem;
			}
		}
	}
}

/*
sắp xếp nhân viên giảm dần theo năm sinh
int tg = a;
a = b;
b = tg;
*/

int main()
{
	Staff one = { "Nguyen Van A", {26, 12, 2000}, 5000, "Nam" };
	Staff two = { "Nguyen Thi B", {29, 11, 1991}, 1000, "Nu" };
	Staff three = { "Nguyen Van C", {17, 10, 1999}, 500, "Nam" };
	Staff four = { "Nguyen Thi D", {11, 18, 1900}, 10, "Nu" };
	LinkedList l;
	init(l);
	addNode(l, one);
	addNode(l, two);
	addNode(l, three);
	addNode(l, four);
	print(l);
	sort(l);
	std::cout << "Danh sach sau khi sap xep: \n";
	print(l);
	NhanVienTren40Tuoi(l);
	std::cout << "So luong nhan vien co luong tren 50$ la: " << SoLuongNhanVienCoLuongTren50Do(l) << std::endl;
	removeAll(l);
	return 0;
}

