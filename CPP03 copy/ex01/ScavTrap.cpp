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
    std::cout << "SlaveTrap Parameterized constructor called" << std::endl;
    health = 100;
    energyPoint = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
    std::cout << "copy constructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &obj)
{
    ClapTrap::operator=(obj);
    std::cout << "copy assignment operator called" << std::endl;
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

void  ScavTrap::takeDamage(unsigned int amount)
{
    if (health > 0)
    {
        if (this->health < (int)amount)
            this->health = 0;
        else
            this->health -= amount;
        std::cout << "ScavTrap " << name << " take damage " << amount << ", health became " << health << " HP" << std::endl;   
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

void ScavTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoint > 0 && this->health > 0)
    {
        this->energyPoint--;
        this->health += amount;  
        if (this->health > 100)
            this->health = 100; 
        std::cout << "ScavTrap " << name << " repaired halth " << amount << ", health became  " << health << " HP" << std::endl;
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