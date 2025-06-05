#include "iter.hpp"


template<typename T>
void UpperCase(T &c)
{
    c = c + 32;
}

int main()
{
    char array[4] = {'A' , 'B' , 'C', 'D'};

    int *a = new int[5];
    a[0] = 2;
    a[1] = 4;
    a[2] = 8;
    a[3] = 16;

    ::iter(array, 4, UpperCase<char>);
    for (int i =0; i < 4; i++)
        std::cout << array[i] << std::endl;
    iter(a, 4, UpperCase<int>);
    for (int i =0; i < 4; i++)
        std::cout << a[i] << std::endl;
    return 0;
}