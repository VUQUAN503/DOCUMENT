#include <iostream>
#include <cmath>
#include <ctime>

int TinhN(int n)
{
	return pow(2, n);
}

/*
hàm tính 2 * n
vd n = 3
=> 2 * 2 * 2 => 2^3
=> n = 4 => 2 * 2 * 2 * 2 => 2 ^ 4
tich = 1
for(int i = n; i >= 1; --i)
	tich *= 2;

i <= n
đk dừng đệ quy chính n = 0
n > 0 

*    0 1 2 3 4   5
A = {1,2,4,8,16,32,...}

*/

int T_(int n)
{
	// tính 2^n; mỗi một lần lặp liên tục nhân chính nó với 2
	int tich = 1;
	for (int i = 1; i <= n; i++)
		tich = tich * 2;
	return tich;
}

int T(int n)
{
	// mỗi một lần gọi đệ quy thì lại lấy chính nó nhân với  2
	/*if (n == 0) return 1;
	return T(n - 1) * 2;*/
	return n == 0 ? 1 : T(n - 1) * 2;
}

int cache[100] = { 0 };
int B(int n) {
	if (n == 0 || n == 1) return 1;
	// xem kết quả đó có ở ngoài nháp chưa nếu chưa có thì đi tính
	if (cache[n] == 0) // trong nháp chưa có => tính
		cache[n] = 2 * B(n - 2) + B(n - 1); // ghi kết quả vừa tính vào nháp
	return cache[n];
	//return n < 2 ? 1 : 2 * B(n - 2) + B(n - 1);
}

int B__(int n) {
	if (n == 0 || n == 1) return 1;
	return n % 2 == 0 ? 2 * B__(n - 1) + 1 : 2 * B__(n - 1) - 1;
	//return n < 2 ? 1 : 2 * B(n - 2) + B(n - 1);
}

int B_(int n) {
	if (n == 0 || n == 1) return 1;
	return 2 * B_(n - 2) + B_(n - 1);
	//return n < 2 ? 1 : 2 * B(n - 2) + B(n - 1);
}


int F(int a)
{
	if (a >= 10) return a * a;
	return a + F(a + 1);
}

long long Fac(int n)
{
	if (n < 2) return 1;
	return Fac(n - 1) * n;
}

int SE(int a[100], int n)
{
	if (n < 0) return 0;
	return a[n] % 2 == 0 ? SE(a, n - 1) + a[n] : SE(a, n - 1);
}

// có thể tối ưu đệ quy chỉ chạy một lần bằng cách sử dụng đệ quy đuôi()

/*
3, 1, 5, 4, 2
SE(a, 4) = 0 + 4 + 2 = 6;
a[4] = 2 => chia hết cho hai
SE(a, 4) = SE(a, 3) + a[4] => 0 + a[3] + a[4]
SE(a, 3) = SE(a, 2) + a[3] => 0 + a[3]
SE(a, 2) = SE(a, 1) => 0
SE(a, 1) = SE(a, 0) =>  0
SE(a, 0) = SE(a, -1) => 0 
SE(a, -1) = 0 
=> 0 

*/

// với a = 4 => 4 < 10 => F(4) = 4 + F(5)
// F(5) = 5 + F(6)
// F(6) = 6 + F(7)
// F(7) = 7 + F(8)
// F(8) = 8 + F(9)
// F(9) = 9 + F(10) 
// f(10) = 100
// => F(5) = 100 + 9 + 8 + 7 + 6 + 5 = 135 + 4 = 139
// oop, cấu trúc, database
int main()
{
	int a[100] = { 3, 1, 5, 4, 2, 10};
	std::cout << "SE: " << SE(a, 5);
	//std::cout << "F: " << F(4) << std::endl;
	/*std::cout << "T_ : " << T_(5) << std::endl;
	std::cout << "T : " << T(5) << std::endl;*/

	//std::cout << "B: " << B(20) << std::endl;
	/*clock_t start = clock();
	std::cout << "B_: " << B_(35) << std::endl;
	clock_t finish = clock();
	clock_t start1 = clock();
	std::cout << "B__: " << B__(35) << std::endl;
	clock_t finish1 = clock();
	std::cout << "Thoi gian de quy nhi phan: " << (double)(finish - start) / CLOCKS_PER_SEC << std::endl;
	std::cout << "Thoi gian de quy tuyen tinh: " << (double)(finish1 - start1) / CLOCKS_PER_SEC;*/
	return 0;
}
/*
*    0 1 2 3 4   5
A = {1,2,4,8,16,32,...}
- Thiết kế giải thuật đệ quy tính số thứ n trong dãy A (n=0,1,2,3….).
- Viết thủ tục đệ quy để tính số n trong dãy A.

với n = 0 => 1
với n = 1 => 2
với n = 2 => 4
2 ^ n

A = {1,1,3,5,11, 21, 43,...}
n =  0,1,2,3,4,  5
n = 0 => 1
n = 1 => 1
n = 2 => 3

2 * T(n - 1) + 1 nếu n chắn
2 * T(n - 1) - 1 nếu n lẻ
vd n = 3 => 2 * T(2)  - 1
   n = 4 => 2 * T(3) + 1


T(n) = 2 * T(n - 2) + T(n - 1)
n = 2 * 1 + 1 = 3
n = 3 = 2 * 1 + 3 = 5
n = 4 => 2 * 3 + 5 = 11
n = 5 = 2 * 5 + 11 = 21
đk dừng n == 0 || n == 1 return 1
n = 3 = 2 * T(1) + T(2)
	 =  2 * 1 + 2 * T(0) + T(1)
	 = 2 + 2 * 1 + 1 = 5


*/