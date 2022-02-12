
#include <iostream>


// tính tổng các số từ 1 đến n sn = 1 + ... + n;

int Sum(int n)
{
    int sum = 0;
    for(int i = 1; 1 < 2; ++i)
    { 
        sum += i;
    }
    return sum;
}

// đệ quy công thức s(n) = s(n - 1) + n với n > 1
//                        = 1 với n = 1

/*
S(5) = 10 + 5
    = 6 + 4
    = 3 + 3
    = 1 + 2
Fibonaci
F(n) = F(n - 1) + F(n - 2) với n > 2
F(n) = 1 với n < 2 >= 0
*/

int S(int n)
{
    if(n == 1) return 1;
    return S(n - 1) + n;
}


// tính số fibonaci f(n) = f(n - 1) + f(n - 2) với n >= 1
 //                        = 1 với n <= 1

int cache[100] = {0};// mảng để đánh dấu lại những kết quả đã được tính
// tính F(5) => cache[5] = giá trị mình vừa tính
int dem = 0;
int F(int n)
{
    dem++;
    if(n <= 1) return 1;
    return F(n - 1) + F(n - 2);
}

int dem_2 = 0;
int F_1(int n)
{
    dem_2++;
    if(n <= 1) return 1;
    if(cache[n] == 0)
    {
        cache[n] = F_1(n - 1) + F_1(n - 2);
    }
    return cache[n];
}
// đệ quy có nhớ(sử dụng bộ nhớ lưu kết quả đã tính trước đó)


int main()
{
    int x;
    std::cout << "Nhap n: ";
    std::cin >> x;
    int n = 50;// 1 + 2 + 3 + 4 + 5
    std::cout << F(n) << std::endl;
    std::cout << "So lan goi ham: " << dem << std::endl;
    // std::cout << F_1(n) << std::endl;
    // std::cout << "So lan goi ham co dung nhap: " << dem_2 << std::endl;
    // std::cout << "Khu de quy: " << Sum(n) << std::endl;
    // std::cout << "De quy: " << S(n) << std::endl;

    return 0;
}
