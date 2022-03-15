#include <list>
#include <iostream>

int main()
{
	/*int* a = new int[5]{ 3, 1, 5, 4, 2 };
	Algorithm::quickSort<int>(a, 0, 4, [](int one, int two) {return two - one; });
	for (int i = 0; i < 5; ++i)
		std::cout << a[i] << " ";*/

	std::list<int> l{3, 1, 5, 4, 2};
	l.push_front(10);
	l.push_back(100);

	for (auto itr = l.begin(); itr != l.end(); ++itr)
		std::cout << *itr << " ";

	std::cout << std::endl << l.back() << " " << l.front() << std::endl;
	
	// dependency injection và lamda expression(con trỏ hàm)
	l.sort([](int one, int two) { return two < one; });
	for (std::list<int>::iterator itr = l.begin(); itr != l.end(); ++itr)
		std::cout << *itr << " ";
	return 0;
}