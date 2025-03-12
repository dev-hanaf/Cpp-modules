#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <cstring>

MateriaSource::MateriaSource() : index(0)
{
    // std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    index = obj.index;
    for (int i =0; i < index; i++)
        inventory[i] = obj.inventory[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
    // std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        index = obj.index;
        for (int i =0; i < index; i++)
            delete inventory[i];
        for (int i =0; i < index; i++)
            inventory[i] = obj.inventory[i];
    }
    return *this;
}
MateriaSource::~MateriaSource()
{
    // std::cout << "MateriaSource Destructor called" << std::endl;
    for (int i =0; i < index; i++)
        delete inventory[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (index < 4)
    {
        inventory[index] = m;
        index++;
    }
    else
        std::cout << "full inventory" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (type != "ice" && type != "cure")
        return 0;
    for (int i=0; i < 4; i++)
    {
        if (inventory[i]->getType() == type)
            return inventory[i]->clone();
    }
    return 0;
}


