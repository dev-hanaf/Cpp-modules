#include "Dog.hpp"
#include "Dog.hpp"
#include "Animal.hpp"


Dog::Dog() : Animal("Dog") 
{

    std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog paremetrized constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    *this = obj;
}

Dog& Dog::operator=(const Dog &obj)
{
    Animal::operator=(obj);
    return  *this;
}
Dog::~Dog(){std::cout << "Dog destructor called" << std::endl;}

void Dog::makeSound() const
{
    std::cout << "bark bark" << std::endl;
}