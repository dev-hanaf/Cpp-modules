#include "easyfind.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>


int main()
{
    std::vector<int> list;
    srand(time(0));
    for(int i=0; i < 10; i++)
    {
        list.push_back(rand() % 10);
        std::cout << i+1 << " ---- " << list[i] << std::endl;  
    }

    std::vector<int>::iterator it =  easyfind(list, 4);
    std::cout << "return value: " << (*it) << std::endl;

    for(; it != list.end(); it++)
    {
        std::cout << (*it) << "\n";
    }
    return 0;
}