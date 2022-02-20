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
void addNode(LinkedList& l, Node *node)
{
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

// tự làm thêm add sau một node bất kỳ, thêm cuối


int main()
{
	LinkedList l;
	init(l);
	// tạo node
	Node* one = createNode(5);
	Node* two = createNode(3);
	Node* three = createNode(1);
	addNode(l, one); // thêm node one vào danh sách
	addNode(l, two);
	addNode(l, three);
	// => one
	// xem dữ liệu của phần tử đầu tiên trong danh sách
	std::cout << l.head->data << std::endl;
	// mình muốn xem data của phần tử thứ hai
	std::cout << l.head->next->data << std::endl;
	std::cout << l.head->next->next->data << std::endl;
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