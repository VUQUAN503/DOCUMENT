#include "Shape.h"

int main()
{
	// one có height là bao nhiêu: 1, 1, 10
	Shape::print();// cách 
	/*
	STATIC(VÙNG NHỚ DÙNG CHUNG)
	BIẾN CỦA CLASS HAY MỌI ĐỐI TƯỢNG ĐỀU DÙNG DUY NHẤT BIẾN ĐÓ(VÙNG NHỚ ĐÓ)
	+ những biến hàm có từ khóa static ở đằng trước thì nó sẽ nằm ở vùng
	+ Khi truy xuất những thuộc tính hay phương thức static ta không dùng đối
	// tượng cụ thể trỏ đến biến đó mà ta dùng Tên của class và toán tử phạm
	// vi(::) để truy xuất vùng nhớ static đó
	+ Nếu lấy tên object cụ thể thuộc class đó trỏ đến vùng nhớ static đó
	// thì object đó đang có chiếm hữu vùng nhớ dùng chung đó thành của riêng mình
	// => bất hợp lý
	+ Một hàm khai báo là static thì chỉ được dùng biến là static
	+ Nếu một class không muốn new đối tượng để chấm đến phương thức =>
	// những phương thức sẽ để là static => chỉ cần lấy tên class chấm luôn

	+ Có một design patern (singleton design pattern)
	design pattern(nguyên tắc vàng trong việc thiết kế phần mềm)
	solid(nguyên lý sống còn)
	*/
	/*Shape* two = one;
	one->setHeight(10);
	std::cout << two->getHeight();*/
	//Shape one(5, 1, 10);
	//Shape two(4, 2.41, 4.5);
	///*std::cin >> one;
	//std::cout << one;*/
	//std::cout << one + two << std::endl;
	//std::cout << (two < 5.0);

	/*
	static(vùng nhớ dùng chung)

	*/
	return 0;
}