#pragma once
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(const std::string &);
        AMateria(const AMateria&);
        AMateria& operator=(const AMateria&);
        virtual ~AMateria();
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};