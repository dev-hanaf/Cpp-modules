#pragma once

#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        int health;
        int energyPoint;
        int attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string);
        ClapTrap(const ClapTrap&);
        ClapTrap &operator=(const ClapTrap&);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};