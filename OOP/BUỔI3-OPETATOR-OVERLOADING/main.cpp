#include "Time.h"
#include "Fraction.h"

int main()
{
	// static, kế thừa
	//Time a;// mặc định
	//Time b(2022);// 1 tham số
	//Time c(2022, 2);// 2 tham số
	//Time d(2022, 2, 18);// 3 tham số
	//Time e(d);// sao chép
	//a.Xuat();
	//b.Xuat();
	//c.Xuat();
	//d.Xuat();
	//e.Xuat();
	/*
	int a = 5;
	int b = ++a; => b = 6 tiền tố tăng trước rồi mới gán
	int c = a++; => 5 hậu tố gán trước rồi mới tăng
	cout << 5;
	cout << Phanso
	iostream 
	ifstream nhập file
	ofstream xuất file
	ostream => cout
	istream => cin
	*/
	Fraction a(1, 2);
	Fraction b(1, 2);
	std::cout << a << std::endl;
	//Fraction c = ++a;// hậu tố => gán trước rồi tăng lên
	// có hai toán tử a++ ++a
	a += b;
	std::cout << a << std::endl; // 3/2
	//c.Xuat(); // 3/2
	// lấy phân số a cộng với phân số b
	/*a.Sum(b).Xuat();
	(a + b).Xuat();
	(a - b).Xuat();
	(a * b).Xuat();
	(a / b).Xuat();*/
	/* 
		khái niệm hàm bạn:
		một hàm được khai báo trong phạm vi class nhưng có từ khoá friend đằng trước
		=> lúc triển khai thì trình biên dịch sẽ hiểu là hàm đó nằm ngoài phạm vi class đó
		nhưng có mối quan hệ bạn bè với nhau
		=> những object thuộc class đó được khai báo trong phạm vi hàm friend
		có thể truy xuất được những thuộc tính, phương thức để là private
	*/
	return 0;
}

// operator overloading