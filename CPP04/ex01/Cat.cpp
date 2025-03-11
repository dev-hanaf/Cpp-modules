#include "Cat.hpp"
#include "Animal.hpp"
#include <string>


Cat::Cat() : Animal("Cat") 
{
    brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(std::string type) : Animal(type)
{
    brain = new Brain();
    std::cout << "Cat paremetrized constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
    brain = new Brain();
    brain = obj.brain;
}

Cat& Cat::operator=(const Cat &obj)
{
    Animal::operator=(obj);
    if (this != &obj)
    {
        delete brain;
        brain = new Brain();
        brain = obj.brain;
    }
    return  *this;
}

Cat::~Cat()
{   delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}