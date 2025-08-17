#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: program must take an inverted Polish mathematical expression as an argument." << std::endl;
        return 1;
    }
    try
    {
        RPN calculator;
        int result = calculator.evaluate(av[1]);
        std::cout << result << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}