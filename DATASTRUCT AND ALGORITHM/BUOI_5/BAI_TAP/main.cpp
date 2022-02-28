#include "D:\MyLib\quan.h"

struct MonHoc {
	std::string maMonHoc;
	std::string tenMonHoc;
	int soTinChi;
};


void nhapThongTinMonHoc(MonHoc& monHoc)
{
	fflush(stdin);
	std::cout << "Nhap ma mon hoc: ";
	std::getline(std::cin, monHoc.maMonHoc);

	std::cout << "Nhap ten mon hoc: ";
	std::getline(std::cin, monHoc.tenMonHoc);

	std::cout << "Nhap so tin chi: ";
	std::cin >> monHoc.soTinChi;
}

void xuatThongTinMonHoc(MonHoc monhoc)
{
	std::cout << "Ten mon hoc: " << monhoc.tenMonHoc << std::endl;
	std::cout << "Ma mon hoc: " << monhoc.maMonHoc << std::endl;
	std::cout << "So tin chi: " << monhoc.soTinChi << std::endl;
}

//B1: Tạo cấu trúc phần tử của danh sách
struct Node {
	MonHoc data;
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
Node* createNode(MonHoc monHoc)
{
	Node* node = new Node;
	if (node == NULL) return NULL;
	node->data = monHoc;
	node->next = NULL;
	return node;
}

// thêm một node vào đầu danh sách
void addNode(LinkedList& l, MonHoc monHoc)
{
	Node* node = createNode(monHoc);
	if (l.head == NULL) l.head = node;
	else {
		node->next = l.head;
		l.head = node;
	}
}

void print(LinkedList l)
{
	for (Node* p = l.head; p != NULL; p = p->next)
		xuatThongTinMonHoc(p->data);
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

// hiển thị thông tin môn học có mã là 123(=>tìm phần tử có giá trị là 3 trong mảng 1 chiều)
Node* searchSubjectWithRollNo(LinkedList l,const std::string &rollNo)
{
	for (Node* p = l.head; p != NULL; p = p->next)
		if (p->data.maMonHoc == rollNo)
			return p;
	return NULL;
}



int main()
{
	LinkedList l;
	init(l);
	MonHoc monHoc;
	nhapThongTinMonHoc(monHoc);
	addNode(l, monHoc);
	print(l);
	Node* node = searchSubjectWithRollNo(l, std::string("123"));
	if (node != NULL) {
		std::cout << "Co tim thay mon hoc co ma la: " << "123\n";
		xuatThongTinMonHoc(node->data);
	}
	else {
		std::cout << "Khong tim thay mon hoc co ma la: " << "123";
	}
	return 0;
}


