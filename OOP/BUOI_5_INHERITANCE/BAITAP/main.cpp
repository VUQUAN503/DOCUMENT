#include "Shape.h"


int main()
{
    Shape a(1, 2, 3, 4), b(1, 2, 3, 4);
    std::cout << *a << std::endl;
    std::cout << (a + b);
    return 0;
}