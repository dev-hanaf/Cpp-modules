// #include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>

bool isTxtFile(const std::string& filename) {
    return filename.rfind(".txt") == (filename.size() - 4);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    if (!isTxtFile(av[1]))
    {
        std::cout << "Error: Not a .txt file." << std::endl;
        return 1;
    }
    return 0;
}