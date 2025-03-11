#include "Animal.hpp"


Animal::Animal() : type("DefaultAnimal"){std::cout << "Animal default constructor called" << std::endl;}
Animal::Animal(std::string type) : type(type){std::cout << "Animal paremetrized constructor called" << std::endl;}
Animal::Animal(const Animal &obj)
{
    *this = obj;
}
Animal& Animal::operator=(const Animal &obj)
{
    if (this != &obj )
    {
        type = obj.type;
    }
    return  *this;
}
Animal::~Animal(){std::cout << "Animal destructor called" << std::endl;}

void Animal::makeSound() const
{
    std::cout << "no Sound" << std::endl;
}

const std::string Animal::getType() const
{
    return type;
}