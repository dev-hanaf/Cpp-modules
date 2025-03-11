#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
}
Cure::Cure(const Cure& obj) : AMateria("cure")
{
    std::cout << "Cure copy constructor called" << std::endl;
    this->type = obj.type;
}

Cure& Cure::operator=(const Cure& obj)
{
    std::cout << "Cure copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        type = obj.type;
    }
    return *this;
}
Cure::~Cure()
{
    std::cout << "Cure Destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    AMateria *obj = new Cure();
    return obj; 
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}