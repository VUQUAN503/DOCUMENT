#include "Student.h"


int Sum(int a, int b)
{
	return a + b;
}

int Sum(int a, int b, int c)
{
	return a + b + c;
}

int main()
{
	/*std::cout << Sum(1, 2) << std::endl;
	std::cout << Sum(1, 2, 3) << std::endl;*/
	Student x; // tạo một object thuộc class Student
	// => nó sẽ ngầm định gọi phương thức khởi tạo mặc định của class đó
	Student y("C-HO");
	return 0;
}





//+ Lập trình tuyến tính
//+ Lập trình thủ tục hàm(tái sử dụng code, rõ ràng dễ tìm bug)
//+ Lập trình hướng đối tượng(OOP - object oriented programming)
//
//class xuất phát từ classify
//+ object là những sự vật hiện tượng mà mình có thể mô tả được nó 
//+ object cấu thành từ 2 thành phần chính
//- thuộc tính: (attribute) những thông tin của object đó
//- phương thức: (method): những hành động
//vd Cat: có thông tin(thuộc tính) : màu lông, cân nặng, ..
//	+ hành động(phương thức): ăn, bắt chuột
//class:
//	+ Gom tất cả các đối tượng có chung đặc điểm(thông tin mả tả của đối tượng đó)
//thành một cái tên duy nhất
//vd: class Car có những đối tượng: ducati, rôn roi, ...
//ducati chính là thể hiện(instance) của class Car
//+ trừu tượng(từ một thứ phức tập mình biến thành một thứ đơn giản hơn nhưng không mất đi bản chất 
//của nó )
//+ đóng gói(khi đã có những tính chất quan trọng của đối tượng đó 
//thì lúc này mình đóng gói chúng lại thành một nhóm chung với một cái tên duy nhất)
//+ kế thừa
//+ đa hình
//+ data access modify(quyền truy cập)
//- public(bất cứ ở đâu mình cũng có thể truy cập được thông tin của class đó)
//- private(chỉ trong phạm vi class đó mới có quyền truy cập)
//- protected
// + Contructor(hàm khởi tạo)
// + Có 3 hàm khởi tạo trong oop c++
// - hàm khởi tạo mặc định
// - hàm khởi tạo có tham số
// - hàm khởi tạo sao chép
// + khi một đối tượng được tạo(được clone) thì nó ngầm định sẻ gọi phương thức khởi tạo
// mặc định của class đó
// + Function Overloading(Nạp chồng hàm)
// - Là hiện tượng các hàm có chùng tên cùng kiểu dữ liệu trả về nhưng khác tham số truyền
// - vào đặc biệt hiện tượng này xảy ra trên bất kỳ class nào
// - Con trỏ this 
// 



