#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string);
        FragTrap(const FragTrap&);
        FragTrap &operator=(const FragTrap&);
        virtual ~FragTrap();
        void highFivesGuys(void);
};