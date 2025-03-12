#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *inventory[4];
        int index;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource&);
        MateriaSource &operator=(const MateriaSource&);
        ~MateriaSource();
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};