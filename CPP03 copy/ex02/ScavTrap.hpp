#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string);
        ScavTrap(const ScavTrap&);
        ScavTrap &operator=(const ScavTrap&);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


