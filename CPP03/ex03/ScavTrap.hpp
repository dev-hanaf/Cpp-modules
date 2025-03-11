#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string);
        ScavTrap(const ScavTrap&);
        ScavTrap &operator=(const ScavTrap&);
        virtual ~ScavTrap();
        void guardGate();
        void attack(const std::string& target);
};


