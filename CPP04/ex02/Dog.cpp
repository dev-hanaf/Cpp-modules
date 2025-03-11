#include "Dog.hpp"
#include "Dog.hpp"
#include "Animal.hpp"


Dog::Dog() : Animal("Dog") 
{
    brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(std::string type) : Animal(type)
{    
    brain = new Brain();
    std::cout << "Dog paremetrized constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    brain = new Brain();
    brain = obj.brain;
}

Dog& Dog::operator=(const Dog &obj)
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
Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}