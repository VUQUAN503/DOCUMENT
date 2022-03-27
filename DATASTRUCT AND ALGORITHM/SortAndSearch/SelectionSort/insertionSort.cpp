#include <iostream>
/*

THUẬT TOÁN SẮP XẾP INSERTION SORT
Bài toán dẫn nhập
-- chèn phần tử x vào mảng(đã đc sắp xếp) sao cho mảng vẫn đc sắp xếp
vd 3 5 7 9
chèn 4 vào
=> 3 4 5 7 9
for(int i = 0; i < n; ++i)
    if(a[i] > x)
        chen(x, i)
chen
for(int i = n - 1; i >= vtchen; --i)
    a[i + 1] = a[i]
a[vtchen] = x
n++


+ ý tưởng thuật toán
- Thuật toán insertion sort sắp xếp dựa trên
không gian đã được sắp xếp một phần ta chỉ thêm phần tử mới vào sao
cho không gian vẫn đc sắp xếp mà thôi

3 1 5 4 2

3 
Nhiệm vụ bây giờ chèn lần lượt từ thằng i + 1 đến n - 1 vào
sao cho mảng vẫn đc sắp xếp
1 2 3 4 5

implement

for(int i = i + 1; i < n; ++i){
    // chèn lần lượt a[i] vào mảng sao cho mảng vẫn đc sắp tăng
}
*/
void InsertionSort(int *array, int len){
    for(int i = 1; i < len; ++i){
        // chèn lần lượt a[i] vào mảng sao cho mảng vẫn đc sắp tăng
        int x = array[i];//
        int j = i - 1;
        while(array[j] > x && j >= 0){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = x; 
    }
}

int main()
{
    int *a = new int[5]{3, 1, 5, 4, 2};
    InsertionSort(a, 5);
    for(int i = 0; i < 5; i++)
        std::cout << a[i] << " ";
    return 0;
}
