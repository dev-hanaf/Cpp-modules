#pragma once

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure&);
        Cure& operator=(const Cure&);
        ~Cure();
        AMateria* clone() const;
        void use(ICharacter &target);
};