

#include <iostream>
#include <ctime>
/*
Bài toán dẫn nhập
+  Tìm phần tử nhỏ nhất trong mảng
*/
int getMin(int *a, int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void SelectionSort(int *array, int len)
{
    for (int i = 0; i <= len - 2; i++)
    {
        // i ở đây là chỉ số đầu tiên của dãy hiện hành
        // đưa phần tử nhỏ nhất của dãy hiện hành về đầu
        int min = array[i];
        for (int j = i + 1; j < len; ++j)
            if (array[j] < min)
                min = array[j];
        // sau khi có được phần tử nhỏ nhất của dãy hiện hành
        std::swap(min, array[i]);
    }
}

void BubbleSort(int *array, int len)
{
    for (int i = 0; i < len; ++i)
        for (int j = len - 1; j > i + 1; --j)
            if (array[j] < array[j - 1])
                std::swap(array[j], array[j - 1]);
}

void init(int *array, int len)
{
    srand(time(NULL));
    for(int i = 0; i < len; ++i)
        array[i] = rand() % 50 + 1;
    // ran dom só ngẫu nhiên từ 1 đến 50
}

// tạo ngẫu nhiên mảng khoảng 50000 phần tử

/*
Ý tưởng thuật toán Selection Sort(Thuật toán sắp xếp chọn)
+ Mình đưa phần tử nhỏ nhất(lớn nhất) về đầu dãy hiện hành
+ Xét đến khi phần tử đầu dãy hiện hành trùng với chỉ số cuối của mảng
vd:
Dãy hiện hành từ 0 đến n - 1
=> mình đưa phần tử nhỏ nhất của dãy hiện hành về 0
Dãy hiện hành từ 1 đến n - 1
=> đưa phần tử nhỏ nhất của dãy hiện hành về 1
 dãy hiện hành từ i đén n - 1
 => đưa phần tử nhỏ nhất dãy hienj hành về i


Đánh giá độ phức tạp
xét vòng lặp trong
int min = array[i]; 1 phép gán
for(int j = i + 1; j <= len - 1; ++j)
    if(array[j] < min) min = array[j];
// sau khi có được phần tử nhỏ nhất của dãy hiện hành
std::swap(min, array[i]); 3 phép(int tg = a[i]; a[i] = a[j]; a[j] = tg)
với mỗi một giá trị j => mất bao nhiêu phép 2 phép
vòng lặp (len - 1 - (i + 1) + 1) lần lặp
mỗi lần mất 2 phép => cả vòng lặp mất
(len - 1 - (i + 1) + 1) * 2

=> cả đoạn code mất (len - 1 - (i + 1) + 1) * 2 + 4 phép
for Ngoài
với i = 0 mất bao nhiêu phép (len - 1 - (0 + 1)) + 1 ) * 2 + 4 phép
với i = 1 mất (len - 1 - (1 + 1)) + 1 ) * 2 + 4
với i = 2 mất (len - 1 - (2 + 1)) + 1 ) * 2 + 4
...
i = len - 3  mất (len - 1 - (len - 3 + 1)) + 1 ) * 2 + 4 = 2 * 2 + 4
với i = len - 2 => (len - 1 - (len - 2 + 1)) + 1 ) * 2 + 4
2 *(len - 1) + 4 +  2 *(len - 2) + 4 + ... + 2*(len - len + 2) + 4 + 2 * 1 + 4
2 * (1 + 2 + ... + (len - 1)) + 4 * (len - 1)

2 *((len *(len - 1))/2) + 4 *(len - 1)
len^2  - len + 4*len - 4
= len^2 + 3*len - 4 => độ phức tạp tổng quát của thuật toán Selection Sort
2len^2 - 2len(Bubble sort)

n = 5 => slection sort = 36
      => bubble sort = 40 => selection sort chạy nhanh hơn
=> O(n^2)

-- Tiến hành đo thời gian chạy của hai thuật toán với mảng khoảng 50000 phần tử

(len - 1)*(len - 1 + 1)/2 = len *(len - 1)/2
tổng từ 1 đến n = n*(n + 1)/2
vd n = 6 = 1 + 2 + 3 + 4 + 5 + 6 = 21
6*(6 + 1)/2 = 42/2 = 21


=>

vd i = 3 ; i <= 5; ++i
=> mất mấy lần lặp (cuối trừ đầu + 1)

*/

int main()
{
    int len = 20000;
    int *array = new int[len];
    init(array, len);
    int *b = new int[len];
    for(int i = 0; i < len; i++)
        b[i] = array[i];
    clock_t start = clock();
    BubbleSort(array, len);
    clock_t end = clock();
    clock_t start1 = clock();
    SelectionSort(b, len);
    clock_t end1 = clock();
    std::cout << "Thoi gian chay cua BubbleSort la: " << (double)(end - start)/CLOCKS_PER_SEC << std::endl;
    std::cout << "Thoi gian chay cua SelectionSort la: " << (double)(end1 - start1)/CLOCKS_PER_SEC << std::endl;
    // tiến hành đo thời gian chạy
    // BubbleSort : 18.289 s
    // SelectionSort: 4.658s, 3.941s
    delete[] array;
    return 0;
}