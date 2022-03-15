


/*Xây dựng bằng danh sách liên kết*/
#include <iostream>


struct Node {
	int data;
	Node* next;
};

Node* createNode(int data)
{
	Node* node = new Node;
	if (node == NULL) return NULL;
	node->data = data;
	node->next = NULL;
	return node;
}

struct Stack {
	Node* top;
};

void init(Stack& s)
{
	s.top = NULL;
}

// hàm kiểm tra xem stack có rỗng không
bool isEmpty(Stack s)
{
	return s.top == NULL;
}

void push(Stack& s, int data)
{
	Node* node = createNode(data);
	// nếu danh sách rỗng
	if (isEmpty(s))
		s.top = node;
	else {
		node->next = s.top;
		s.top = node;
	}
}

// xóa phần đầu tiên trong stack
void pop(Stack& s)
{
	if (isEmpty(s))
		return;// danh sách rỗng => không xóa đc
	Node* node = s.top;
	if (s.top->next == NULL)
	{
		delete node;
		s.top = NULL;
	}
	else {
		s.top = s.top->next;
		delete node;
	}
}


// viết hàm duyệt stack
void print(Stack s)
{
	/*for (Node* p = s.top; p != NULL; p = p->next)
		std::cout << p->data << " ";*/

	 //khi mà trong ngăn xếp còn phần tử
	while (!isEmpty(s))
	{
		// xem phần tử đầu tiên
		std::cout << s.top->data;
		// xem xong rồi thì phải bỏ nó ra ngoài còn xem đc thằng ở dưới
		pop(s);
	}
}

void toBinary(int number)
{
	Stack s;
	init(s);
	while (number != 0)
	{
		push(s, number % 2);
		number /= 2;
	}
	print(s);
}


/*
Chuyển số thập phân sang các hệ 2 8 16

11 -> chuyển sang hệ hai
11 / 2 = 5 dư 1
5 / 2 = 2 dư 1
2 / 2 = 1 dư 0
1 / 2 = 0 dư 1
in ngược lại 1011
bát phân và thập lục phân tương tự(không đơn giản như hệ 8 và 2)

*/

int main()
{
	toBinary(99);
	//Stack s;
	//init(s);
	//push(s, 1);
	//push(s, 1);
	//push(s, 0);
	//push(s, 1);
	//// => s: 7 2 1 10
	//print(s);
	return 0;
}