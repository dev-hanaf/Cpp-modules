#include <iostream>

int main(void)
{
    std::string var = "HI THIS IS BRAIN";
    std::string *ptr = &var;
    std::string &ref = var;

    std::cout << "The memory address of the string variable " << &var << std::endl;
    std::cout << "The memory address held by stringPTR " << ptr << std::endl;
    std::cout << "The memory address held by stringREF " << &ref << std::endl;

    std::cout << "The value of the string variable " << var << std::endl;
    std::cout << "The value pointed to by stringPTR " << *ptr << std::endl;
    std::cout << "The value pointed to by stringREF " << ref << std::endl;
}