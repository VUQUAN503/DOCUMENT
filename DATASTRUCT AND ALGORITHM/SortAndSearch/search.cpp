

/*
TÌM KIẾM
+ Tìm kiếm trên không gian đã sắp xếp(tìm kiếm nhị phân)
+ Tìm kiếm trên không gian chưa đc sắp xếp(tuần tự, lính canh)


- Tuần Tự(vét cạn)
+ ý tưởng thuật toán: Duyệt từ phần tử đầu tiên cho đến khi thấy thì thôi
 for(v : {})
	+ Nếu x == v -> kết thúc và tìm thấy
 -> Nếu kết thúc vòng lặp -> không tìm thấy


int a[] = {3, 1, 5, 4, 2}
x = 5

for(int i = 0; i < 5; ++i)
	if(a[i] == x) return 1;

return 0;
 + Đánh giá độ phức tạp của thuật toán
+ Tốt nhất: phần tử cần tìm của mình nó nằm ở vị trí đầu tiên
=> độ phức tạp O(1)

+ Trung bình: thì phần tử cần tìm của mình nằm ở giữa dãy
=> độ phức tạp O(n/2)

+ Xất nhất: thì phần tử của mình nằm ở cuối
=> độ phức tạp của nó là O(n)

=> độ phức tạp chung của thuật toán là: O(n)

- Đặt lính canh(cải tiến của thuật toán tuần tự)
ý tưởng thuật toán:
+ khi mà phần tử a[i] còn khác x mình tăng chỉ số i lên
+ Nếu mà i nằm trong khoảng chỉ số của mảng => tìm thấy
+ Ngược lại không tìm thấy

int i = 0;
while(a[i++] != x)
if(i - 1 < n) return 1;
return 0;

for(int i = 0; i < 5; ++i)
	if(a[i] == x) return 1;

-- Tìm kiếm nhị phân(chỉ tìm trên không gian đã đc sắp xếp)
Ý tưởng: chia không gian cần tìm thành 2 không gian nhỏ hơn
ngăn cách nhau bằng phần tử mid(mid = chỉ số đầu + chỉ số cuối / 2)
+ Nếu phần tử cần tìm > phần tử tại vị trí mid
=> mình sẽ tìm trong không gian mid + 1 -> right
+ Nếu phần tử cần tìm < phần tử tại vị trí mid
=> mình tìm trong không gian left -> mid - 1
Nếu phần tử cần tìm bằng luôn với phân tử ngăn cách => tìm thấy

void binarySearch(int *a, int n, int x)
{
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(x > a[mid]) left = mid + 1;
        else if(x < a[mid]) right = mid - 1;
        else return 1;
    }
    return 0;
}

// đệ quy
int search(int *a, int left, int right, int x)
{
    if(left > right) return -1;
    int mid = (left + right) / 2;
    if(a[mid] < x) search(a, left, mid - 1, x);
    else if(a[mid] > x) search(a, mid + 1, right, x)
    else return 1;   
}

Đánh giá độ phức tạp thuật toán
+ tốt nhất: giữa => O(1)
+ trung bình: có biết trước đc số lần chia 12 => tb chia 2 lần
xấu nhất: chia đến khi nào mảng còn 1 phần tử
n/2/2/2/2 cho đến khi nào = 1
-> tổng quát mất k phép chia
n/2^k = 1 => k = log2(n)
=> độ phức tạp chung của thuật toán O(log(n))

-- Quick sort: O(n*log(n))

-----------------SORT
+ Interchange sort(sắp xếp đổi chỗ trực tiếp)
+ Bubble sort(sắp xếp nổi bọt)
-- Ý tưởng thuật toán:
Với mỗi một phần tử trong dãy thì làm
+ Từ cuối dãy mình liên tục so sánh cặp phần tử cuối với nhau
+ Nếu hai phân không theo quy tắc ban dầu(giảm dần hay tăng dần) => mình 
đổi chỗ 2 phần tử cho nhau
Lặp đến khi mảng của mình ko còn phần nào để xét
for(int i = 0; i < n; ++i)
{
    for(int j = n - 1; j >= i + 1; --j)
    {
        if(a[j] < a[j - 1])
        {
            int tg = a[j];
            a[j] = a[j - 1];
            a[j - 1] = tg;
        }
    }
}

// Đánh giá độ phức tạp
xét vòng lặp trong trước
với mỗi một giá trị j => mất bao nhiêu phép 4 phép tính
=> vòng lặp (j - (i + 1)) + 1 lần mà mỗi lần mất phép 4 phép
với i = 0 => mất(n - 1 - (0 + 1) + 1) => mất (n - 1) * 4 phép
với i = 1 mất (n - 2) * 4 phép
với i = n - 1 => mất (n - 1 - (n - 1 + 1) + 1)* 4 = 0 phép
=> 4* ( (n - 1) + (n - 2) + (n -3) + ...(n - (n - 1)) + (n - n))
4*(1 + 2 + 3 + 4 + (n - 1))
4 * (n - 1)*(n - 1 + 1)/2
= 4*n*(n - 1)/2 
2*n*(n - 1) = 2n^2 - 2n
=> đọ phức tạp chung O(n^2)

+ tổng các số từ 1 đến n = n*(n + 1)/2
vd 1 + 2 + 3 + 4 + 5 = 5*6/2 = 15

vd vòng lặp chạy trong khoảng a -> b
=> số lần lặp b - a + 1
vd 3 5
+ Selection sort()
+ Insertion sort
+ merge Sort()
+ quick sort(4000000)
+ heap sort

*/
















