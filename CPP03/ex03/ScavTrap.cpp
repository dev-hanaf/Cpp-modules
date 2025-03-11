#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("DefaultScavTrap")
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    health = 100;
    energyPoint = 50;
    attackDamage = 20;
    
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Parameterized constructor called" << std::endl;
    health = 100;
    energyPoint = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &obj)
{
    ClapTrap::operator=(obj);
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void  ScavTrap::attack(const std::string& target)
{
    if (energyPoint > 0 && health > 0)
    {
        this->energyPoint--;
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;   
    }
    if (health <= 0 )
    {
        std::cout << "ScavTrap " << name << " is Dead" << std::endl;
    }
    else if (energyPoint <= 0)
    {
        std::cout << "ScavTrap " << name << " has no energy point left to attack" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    if (this->energyPoint > 0 && this->health > 0)
    {  
        std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
    }
    if (health <= 0 )
    {
        std::cout << "ScavTrap " << name << " is Dead" << std::endl;
    }
    else if (energyPoint <= 0)
    {
        std::cout << "ScavTrap " << name << " has no energy point left to attack" << std::endl;
    }
}