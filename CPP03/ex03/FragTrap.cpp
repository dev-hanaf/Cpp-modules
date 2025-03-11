#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultFragTrap")
{
    std::cout << "FragTrap default constructor called" << std::endl;
    health = 100;
    energyPoint = 100;
    attackDamage = 30;
    
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap Parameterized constructor called" << std::endl;
    health = 100;
    energyPoint = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap &obj)
{
    ClapTrap::operator=(obj);
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}