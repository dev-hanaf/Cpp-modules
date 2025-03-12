#include "Character.hpp"
#include "AMateria.hpp"
#include <cstring>

Character::Character()
{
    std::memset(&inventory, 0, sizeof(inventory));
    // std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string& name) : name(name)
{
    std::memset(&inventory, 0, sizeof(inventory));
    // std::cout << "Character Param constructor called" << std::endl;
}

Character::Character(const Character& obj)
{
    // std::cout << "Character copy constructor called" << std::endl;
    name = obj.name;
    for (int i =0; i < 4; i++)
        inventory[i] = obj.inventory[i];
}

Character& Character::operator=(const Character& obj)
{
    // std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        name = obj.name;
        for (int i =0; i < 4; i++)
            delete inventory[i];
        for (int i =0; i < 4; i++)
            inventory[i] = obj.inventory[i];
    }
    return *this;
}
Character::~Character()
{
    // std::cout << "Character Destructor called" << std::endl;
    for (int i =0; i < 4; i++)
        delete inventory[i];    
}

std::string const & Character::getName() const  
{
    return name;
}

void Character::equip(AMateria *m)
{
    for (int i=0; i < 4 ;i++)
    {
        if (inventory[i] == 0)
        {
            inventory[i] = m;
            return;
        }
    }
    std::cout << "inventory full" << std::endl;
}


void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
    {
        // store Materia before set null on it
        inventory[idx] = 0;
    }
}


void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3)
    {
        inventory[idx]->use(target);
    }
} 
