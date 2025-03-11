#include "Cat.hpp"
#include "Animal.hpp"


Cat::Cat() : Animal("Cat") 
{

    std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat paremetrized constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
    *this = obj;
}

Cat& Cat::operator=(const Cat &obj)
{
    Animal::operator=(obj);
    return  *this;
}
Cat::~Cat(){std::cout << "Cat destructor called" << std::endl;}

void Cat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}