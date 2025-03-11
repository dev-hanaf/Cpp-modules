#pragma once

#include "AMateria.hpp"

class Character
{
    private:
        std::string name;
    public:
        Character();
        Character(const std::string &);
        Character(const Character &);
        Character &operator=(const Character&);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);    
};