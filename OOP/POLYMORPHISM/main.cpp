#include <iostream>


class Animal {
protected:
	std::string color;
	double weight;
public:
	Animal(const std::string &color, double weight) : color(color), weight(weight){}
	// ảo
	virtual void run() {
		std::cout << "Animal is running" << std::endl;
	}
};

// phương thức thuần ảo(abstract class/interface)
// tính trừu tượng abstraction
class Dog : public Animal {
public:
	Dog(const std::string& color, double weight) : Animal::Animal(color, weight) {}
	void run() {
		std::cout << "Dog is running" << std::endl;
	}

	void eat()
	{
		std::cout << "Dog is eating" << std::endl;
	}
	/*
	+ phân tích nghiệp vụ khách hàng(phỏng vấn nhu cầu khác hàng(lập phiếu phỏng vấn, phiếu điều tra))
	+ Vẽ sơ đồ use case (là sơ đồ mô phỏng sự tương tác của người dùng với chức năng hệ thống)
	+ thiết kế cơ sở dữ liệu
	+ lập trình
	+ test
	*/
};

class Cat : public Animal{
	
public:
	Cat(const std::string& color, double weight) : Animal::Animal(color, weight) {}
	void run() {
		std::cout << "Cat is running" << std::endl;
	}

	void chaseMouse()
	{
		std::cout << "Cat is chasing the mouse" << std::endl;
	}
	// O(n), O(n^2), i *= 2 O(n*log(n))
	// dùng cộng là lấy lớn nhất trong hai cái 
	// dùng nhân 
	/*
	phép gán, so sánh, cộng, trừ nhân chia cơ bản sẽ là O(1)
	int a = 10;
	a += 5;
	O(2), O(1) => max(1, 1) = 1=> O(1)

	for(int i = 1; i <= 10; i += 2)
		for(int j = i + 1; j <= 10; ++j)
	O(n^2)
	với mỗi giá trị i đoạn chương trình bên trong vòng lặp chạy 1 lần
	=> vòng lặp chạy n lần thì độ phức tạp là O(n)
	 với i bằng 1 thì mất 9 lần
	 với i = 3 thì chạy mấy 7 lần
	 với i = n thì chạy mất n - i làn chạy
	 tổn 1 + 1 + 1 + . 1 + 1. = mất 50 lần chạy
	*/
};

int main()
{
	// arr là mảng con trỏ đối tượng thuộc class Animal
	Animal* arr[15];
	// phần tử đầu tiên của mảng con trỏ đối tượng animal đang 
	// trỏ đến vùng nhớ của đối tượng dog
	arr[0] = new Dog("red", 3.4f);
	arr[1] = new Dog("yellow", 10.0f);
	arr[2] = new Cat("green", 4.3f);
	arr[3] = NULL;
	for (int i = 0; i < 4; ++i)
		arr[i]->run();
	/*
	* => một cái cực kỳ hay và quan trọng là:
	* Ta có thể gom những đối tượng thuộc class khác nhau vào chung một 
	* nhóm với một tên gọi duy nhất
	* 
	*/
	//arr[0]->run();// hiện tượng đa hình(con qua mặt cha hay gọi hàm của cha nhưng lại chạy con)
	//arr[1]->run();
	//arr[2]->run();
	/*Animal* animal = new Animal("pink", 3.4f);
	animal->run();
	Dog* dog = new Dog("yellow", 12.5f);
	dog->run();
	dog->eat();*/
	//Animal* dog = new Dog("red", 3.5f);// kỹ thuật này cực kỳ quan trọng
	//dog->run();
	//Animal* cat = new Cat("grey", 1.5f);
	//cat->run();
	//((Dog*)a)->eat();
	/*
	Khai báo con trỏ đối tượng thuộc lớp cha nhưng lại new ra vùng nhớ của con
	-> hợp lí vì trong vùng nhớ con đã chứa sẵn vùng nhớ rồi mà lại có thêm những mở rổng nếu con triển khai thêm
	Khai con new cha thì sẽ không được vì vùng nhớ của con thì to nhưng lại new ra vùng nhớ bé xíu thì sao mad
	con có thể vào ở được
	--- 
	Bây giờ cha tò mò muốn biết thêm thằng con có gì thì làm sao
	có thể xem được
	=> liên quan đến một kỹ thuật risk con trỏ
	con trỏ đối tượng cha chỉ chỏ được đến đáy của vùng nhớ cha thôi bay giờ làm sao để nó trỏ được đến đáy của vùng
	nhớ con => mình sẽ kéo sợi dây chun xuống dưới để nó nhìn thấy đc toàn bộ vùng nhớ của con
	
	vd:
	Bác Hồ kêu gọi toàn thể nhân dân đánh giặc
	Thì ai có súng dùng súng, ai có dao dùng dao, ai có gậy dùng gậy
	=> Từ một lời nói đánh giặc của bác hồ nhưng có n cách triển khai 
	hành động đó, xuất phát từ một lời nói nhưng có n cách thể hiện,
	thực hiện lời nói đó
	=> nó là tính chất đa hình , đa ánh xạ, đa sắc thái, đa nhân cách
	cha chỉ nói thôi còn con triển khai như nào là việc của thằng con
	con sẽ implement(triển khai) hành động của cha nhưng theo cách của con
	//
	Khi phương thức(hành động) của cha có từ khóa virtual đằng trước
	thì đây sẽ là một phương thức ảo tức là nó chỉ một lời nói 
	khi con kế thừa từ cha thì con sẽ thực hiện hành đọng đó theo cách
	của riêng con => Đây là hiện tượng con qua mặt cha(đa hình)
	=> cha nói nhưng lại không làm => Con sẽ qua mặt 
	Gọi hàm của cha nhưng lại chạy hàm của con => đây là hiện tượng 
	đa hình, đa xạ, đa sắc thái

	*/
	return 0;
}