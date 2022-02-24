#include <iostream>

// Bước 1: Tạo cấu trúc để biểu diễn thông tin của một node
// một node có 2 thành phần { giá trị và con trỏ lưu trữ địa chỉ của node tiếp theo}
struct Node {
	// thành phần dữ liệu (int, double, float, char, SinhVien, C-Hó)
	int data;
	// thành phần con trỏ nó sẽ giữ địa chỉ của node tiếp theo
	// => con trỏ này nó sẽ có kiểu gì => vd muốn lưu địa chỉ của số nguyên => cần con trỏ
	// số nguyên 
	Node* next;
};

// Bước 2: Tạo phần tử(node)
// hàm nó sẽ trả về địa chỉ của một node (vì có địa chỉ => giá trị của node
// => muốn lấy giá trị node đó thì mình làm gì
// vd Địa chỉ của một nốt là x => muốn lấy được giá trị của node đấy
// Sinh Vien x => muốn lấy tên của sinh viên x đó x.name
// => có một địa chỉ của một node x => mình muốn trỏ đến thành phần dữ liệu của node đấy
// => x->data; -> (arow) toán tử trỏ)
// trả về một số nguyên => int <Tên hàm> , muốn trả về một con trỏ kiểu số nguyên 
// => int* <Tên hàm> => Muốn trả về địa chỉ kiểu nodde => Node * <Tên hàm>
// muốn tạo 1 node => cái quan trọng nhất chính là data của node int a = 10;
Node* createNode(int data)
{
	// int *a = new int // cấp phất ra một ô nhớ mới cho con trỏ trỏ đến
	// => Lúc này để tạo được một node mình phải cho nó một chỗ để chứa nó(hay là một vùng nhớ mới)
	// => cấp phát ra một vùng nhớ để lưu trữ giá trị node
	Node* node = new Node;
	// nếu trong trường hợp máy tính hết ram(bộ nhớ chả hạn)
	if (node == NULL)// tức là không cấp phát được =>
		return NULL;// thông báo cấp phát hay tạo node ko thành công
	// => khi đã có vùng nhớ rồi thì => gán giá trị cho nó
	node->data = data; // gán dữ liệu cho giá trị của node
	// null pointer exception(truy cập vùng nhớ không hợp lệ)
	// khi mới sinh ra thì chưa biết ai để liên lạc
	// tức là mình đang đơn lẻ, một mình => số liên lạc của mình sẽ không có ai hay không
	// có bạn bè trên fb
	// vd muốn lấy số liên lạc của b => x->next = địa chỉ b(số điện thoại của b)
	node->next = NULL;// tao chưa cần biết tao liên lạc với ai
	// Sau khiâuọ xong các thành phần của node rồi => 
	return node;
}

// Bước 3: Khởi tạo danh sách
// tạo ra danh sách gồm con trỏ dữ địa chỉ của phần tử đầu tiên
// int a[5] là một mảng có n số nguyên
// danh sách liên kết gồm có n node
struct LinkedList {
	// chỉ quan tâm đến địa chỉ của phần tử đầu tiên trong danh sách
	Node* head;// danh sách nó sẽ lưu trữ địa chỉ của phần tử đâu tiên
	// muốn truy cập được những phần tử tiếp theo thông qua con trỏ next
};

// khởi tạo một danh sách => cho phần tử đầu tiên = NULL
void init(LinkedList &l)
{
	// khởi tạo danh sách rỗng ban đầu
	l.head = NULL;
}

// Bước: 4 Thêm một node(thêm đầu, thêm cuối, thêm giữa)
void addNode(LinkedList& l, int data)
{
    Node* node = createNode(data);
	// kiểm tra xem danh sách có đang rỗng hay không nếu rỗng thì gán luôn nó bằng 
	// phần tử đầu tiên trong danh sách
	if (l.head == NULL) // nếu danh sách rỗng
	{
		l.head = node;
	}
	else {
		// danh sách có phần tử rồi
		node->next = l.head;
		l.head = node;
	}
}

void addTail(LinkedList &l, int data)
{
    Node* p = createNode(data);
    if(l.head == NULL) // danh sách rỗng
        l.head = p;
    else{
        //b1: tìm thằng cuối cùng
        Node*k = l.head;
        while(k->next != NULL) k = k->next;
        // sau vòng lặp này k trỏ đến pt cuối cùng
        // =? chỉ cần cho k-> next = cần thêm là xong
        k->next = p;
    }
}

void add(LinkedList &l, int ptchen, int data)
{
    Node *node = createNode(ptchen);
    if(l.head == NULL) l.head = node;
    else{
        //b1: tìm thằng trước pt mình muốn chèn vào
        Node* p = l.head;
        Node* k;
        while(p != NULL && p->data != data)
        {
            k = p;// gán k = p trước khi nó nhảy sang thằng tiếp theo
            // mục đích lưu lại thằng trước pt mình cần tìm
            p = p->next;
        }
        // sau khi kết thúc vòng lặp thí p là node có data là data mình truyền
        // node k là node trước node p
        // => thực hiện bẻ mối liên kết
        k->next = node;
        node->next = p;
    }
}
//BƯỚC 5: XÓA
void remove(LinkedList &l, int data)
{
    // nếu danh sách rỗng 
    if(l.head == NULL) return;
    // danh sách rỗng thì không xóa
    //b1: tìm thằng trước pt mình muốn chèn vào
    Node* p = l.head;
    Node* k;
    while(p != NULL && p->data != data)
    {
        k = p;// gán k = p trước khi nó nhảy sang thằng tiếp theo
        // mục đích lưu lại thằng trước pt mình cần tìm
        p = p->next;
    }
    // sau khi kết thúc vòng lặp thí p là node có data là data mình truyền
    // node k là node trước node p
    k->next = p->next;
    // sau khi bẻ mối thì p bơ vơ => cần phải giải thoát
    delete p;
}


void removeHead(LinkedList &l)
{
    if(l.head == NULL) return;// danh sách rỗng => không xóa
    Node *p = l.head;// tạo ra một con trỏ trỏ đến phần tử đầu tiên
    // => cho l.head nhảy sang phần tử tiếp theo nhỡ không thằng p nó hâm đốt nhà
    // không chạy thì chỉ có chết => chạy
    // nếu mà danh sách chỉ có một phần tử thì làm sao => không còn chỗ nương thân
    // => chấp nhận chết thôi
    if(l.head->next == NULL) {// không có ai để nương tựa
        delete p;
        l.head = NULL;
    }
    else{
        l.head = l.head->next;// cho nó nhảy sang nhà thằng bên cạnh
        //=> đốt nhà thôi
        delete p;
    }
}

void removeTail(LinkedList &l)
{
    if(l.head == NULL) return;
    // danh sách có 1 phần tử
    if(l.head->next == NULL){
        delete l.head;
        l.head = NULL;
    }
    else{
        Node* p = l.head;
        Node* k;
        while(p->next != NULL){
            k = p;
            p = p->next;
        }
        k->next = NULL;
        delete p;
    }
}

void input(LinkedList &l, int n)
{
    for(int i = 0; i < n; ++i)
    {
        int data;
        std::cout << "L[" << i << "] = ";
        std::cin >> data;
        addNode(l, data);
    }
}

// tự làm thêm add sau một node bất kỳ, thêm cuối


void print(LinkedList l)
{
    for(Node *p = l.head; p != NULL; p = p->next)
        std::cout << p->data << " ";
}

// BƯỚC 7: GIẢI PHÓNG CÂY
void removeAll(LinkedList &l)
{
    while(l.head != NULL)
    {
        Node*p = l.head;
        l.head = l.head->next;
        delete p;
    }
}

int main()
{
	LinkedList l;
	init(l);
	// tạo node
    // addNode(l, 1);
    // addTail(l, 2);
    // addTail(l, 5);
    // addTail(l, 4);
    // addTail(l, 3);
    // add(l, 100, 5);
    // remove(l, 5);
    // removeHead(l);
    // removeTail(l);
    // 2 100 4
    input(l, 5);
    print(l);
	// => one
	// xem dữ liệu của phần tử đầu tiên trong danh sách
	// std::cout << l.head->data << std::endl;
	// // mình muốn xem data của phần tử thứ hai
	// std::cout << l.head->next->data << std::endl;
	// std::cout << l.head->next->next->data << std::endl;
	/* MỌI NGƯỜI TÌM HIỂU CON TRỎ HÀM(FUNCTION POINTER) => LAMBDA EXPRESSION(
	dependency injection) SOLID -> DEPENDENCY INVERSION PRINCIPLES
	*/
	/*
	struct là kiểu dữ liệu cấu trúc => kiểu dữ liệu trừu tương
	=> không thể biểu diễn kiểu dữ liệu đó bằng các kiểu dữ liệu nguyên thuỷ như int, double..
	vd như : SinhVien, C-Hó
	=> Để biểu diễn được thông tin dữ liệu đó mình gom tất cả thông tin đơn lẻ(mà có thể biểu diễn
	bằng kiểu dữ liệu có sẵn) của nó 
	thành một nhóm với cái tên duy nhất
	vd SinhVien => mình sẽ gom những thông tin mã số(char []), tuổi(int), điểmTB(float/double)
	Cú pháp
	struct <Tên kiểu dữ liệu do mình định ngĩa>{
		// gồm những thông tin đơn lẻ của dữ liệu đó
	};
	// vd Sinh Viên
	struct Student{
		char name[20],
		int age;
		double grade;
	};
	=> Muốn truy xuất được từng thông tin đơn lẻ của biến trừu tượng => mình dùng dấu (.)
	vd muốn lấy thông tin tên của Sinh Viên X => X.name 
	*/
	//int a = 10;// máy tính tạo ra một vùng ram trong vùng nhớ stack chứa biến a
	//int b = a; // máy tính sẽ tạo ra một vùng nhớ mới chứa biến b và gán giá trị của a cho b
	///*std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << &a << std::endl;
	//std::cout << &b << std::endl;*/
	//int* c = &a;// tạo ra một con trỏ trỏ đến địa chỉ của biến a => hai chàng một nàng
	//std::cout << a << std::endl;
	//std::cout << *c << std::endl;
	//std::cout << &a << std::endl;
	//std::cout << c << std::endl;

	// => một ông ngứa mắt đành nàng chả hạn => ông kia  
	// khi một trong giá trị của hai thằng thay đổi => cả hai sẽ bị ảnh hưởng theo
	/* khái niệm
	Có hai laoij vùng nhớ
	+ Stack: vùng nhớ do máy tính quản lý(int a, int b) => nó sẽ tự động giải phóng vùng nhớ khi
	hết phạm vi sử dụng
	+ Heap: Do người lập trình quản lý(int *a = new int => giải phóng delete a ) => mình phải giải phóng vùng nhớ đó
	nếu không nó sẽ vẫn còng trong ram khi trương trình tắt => tốn bộ nhớ
	=> dùng toán tử delete để giải phóng
	Con trỏ là một biến địa chỉ(lưu trữ địa chỉ của biến khác hoặc mình sẽ cấp phát 
	cho nó một địa chỉ(int *a = new int)
	)
	*/

	return 0;
}