#include "Character.hpp"

Character::Character()
{
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string& name) : name(name)
{
    std::cout << "Character Param constructor called" << std::endl;
}

Character::Character(const Character& obj)
{
    std::cout << "Character copy constructor called" << std::endl;
    name = obj.name;
}

Character& Character::operator=(const Character& obj)
{
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        name = obj.name;
    }
    return *this;
}
Character::~Character()
{
    std::cout << "Character Destructor called" << std::endl;
}

std::string const & Character::getName() const  
{
    return name;
}

// ~