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
	// ORM(object relational mapping)
	//std::cout << "Sum of five numbers is: " << Sum(5, [](int one, int two) {return one - two; }, 3, 2, 1, 5, 4) << std::endl;
	/*std::cout << Sum(1, 2) << std::endl;
	std::cout << Sum(1, 2, 3) << std::endl;*/
	//Student x; // tạo một object thuộc class Student
	//// => nó sẽ ngầm định gọi phương thức khởi tạo mặc định của class đó
	//Student y("C-HO");
	//std::cout << y.name << " : " << y.rollNo << " : " << y.age << std::endl;
	//int a = 5;
	//Student(std::string name, std::string rollNo, int age) {
	//	std::cout << "ham khoi tao 3 tham so" << std::endl;
	//	this->name = name;
	//	this->rollNo = rollNo;
	//	this->age = age;
	//	// hàm khởi tạo 3 tham số
	//};
	//int b = a;// sao chép giá trị b cho a
	//Student z("Nguyen Van A", "2020606122", 19);
	//std::cout << z.name << " : " << z.rollNo << " : " << *(z.age) << std::endl;
	//Student k = z;
	//*(k.age) = 20;
	//std::cout << "Tuoi cua z: " << * (z.age) << std::endl;
	Student x("Dinh Khac Tuan", "2020606122", 19);
	std::cout << x.getName() << std::endl;
	x.setName("Tuan Mom");
	std::cout << x.getName() << std::endl;
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
//	+ Gom tất cả các đối tượng có chung đặc điểm(thông tin mả tả của đối tượng đó), hành vi(behevior)
//thành một cái tên duy nhất
//vd: class Car có những đối tượng: ducati, rôn roi, ...
//ducati chính là thể hiện(instance, object) của class Car
//+ trừu tượng(abstraaction)(từ một thứ phức tập mình biến thành một thứ đơn giản hơn nhưng không mất đi bản chất 
//của nó)
//+ đóng gói(encapsulation)(khi đã có những tính chất quan trọng của đối tượng đó 
//thì lúc này mình đóng gói chúng lại thành một nhóm chung với một cái tên duy nhất)
//+ kế thừa
//+ đa hình
//+ data access modify(quyền truy cập)
//- public(bất cứ ở đâu mình cũng có thể truy cập được thông tin của class đó)
//- private(chỉ trong phạm vi class đó mới có quyền truy cập)
//- protected
// + Contructor(hàm khởi tạo : tự động được gọi khi một đối tượng được tạo ra tuỳ thuộc cách đúc(tạo object) khác nhau)
// + Có 3 hàm khởi tạo trong oop c++
// - hàm khởi tạo mặc định(default constructor)
// - hàm khởi tạo có tham số(constructor with parameter)
// - hàm khởi tạo sao chép(copy constructor)
// + Hàm huỷ(Deconstructor) -> tự động được gọi khi đối tượng không còn phạm vi sử dụng nữa 
//		(có thể lợi dụng ưu điểm của nó để giải phóng con trỏ nếu trong phạm vi class đó có khai báo những biến kiểu con trỏ))
// + khi một đối tượng được tạo(được clone) thì nó ngầm định sẻ gọi phương thức khởi tạo
//  mặc định của class đó
// + Function Overloading(Nạp chồng hàm)
// - Là hiện tượng các hàm có chùng tên cùng kiểu dữ liệu trả về nhưng khác tham số truyền
// - vào đặc biệt hiện tượng này xảy ra trên bất kỳ class nào
// - Con trỏ this (con trỏ đối tượng hiện thời)
// - getter setter
// 



