#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "Ice default constructor called" << std::endl;
}
Ice::Ice(const Ice& obj) : AMateria("ice")
{
    // std::cout << "Ice copy constructor called" << std::endl;
    this->type = obj.type;
}

Ice& Ice::operator=(const Ice& obj)
{
    // std::cout << "Ice copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        type = obj.type;
    }
    return *this;
}
Ice::~Ice()
{
    // std::cout << "Ice Destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    AMateria *obj = new Ice();
    return obj; 
}

void Ice::use(ICharacter &target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}