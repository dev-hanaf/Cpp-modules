#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() :    ClapTrap("DefaultDiamond_clap_name"), FragTrap("DefaultDiamond_clap_name") , ScavTrap("DefaultDiamond_clap_name")
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->name = "DefaultDiamond";
    health = 100;
    energyPoint = 50;
    attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name+"_clap_name") ,FragTrap(name+"_clap_name") ,  ScavTrap(name+"_clap_name")
{
    std::cout << "DiamondTrap Parameterized constructor called" << std::endl;
    std::cout << "old Traps " << ClapTrap::name << std::endl;
    
    this->name = name;
    std::cout << "Diamond " << this->name << std::endl;
    health = 100;
    energyPoint = 50;
    attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) :ClapTrap(obj), FragTrap(obj) , ScavTrap(obj)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap &obj)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.name;
        ClapTrap::operator=(obj);
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << name << std::endl;
    std::cout << ClapTrap::name << std::endl;
}
