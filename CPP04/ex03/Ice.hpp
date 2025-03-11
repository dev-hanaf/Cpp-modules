#pragma once

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
    private:
        std::string name;
    public:
        Ice();
        Ice(const Ice&);
        Ice& operator=(const Ice&);
        ~Ice();
        AMateria* clone() const;
        void use(ICharacter& target);
};