#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
    :name("DefaulClapTrap"),  health(10) , energyPoint(10) , attackDamage(0)
{
    std::cout << "default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name),  health(10) , energyPoint(10) , attackDamage(0)
{
    std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
    : name(obj.name), health(obj.health), energyPoint(obj.energyPoint), attackDamage(obj.attackDamage)
{
    std::cout << "copy constructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.name;
        this->health = obj.health;
        this->energyPoint = obj.energyPoint;
        this->attackDamage = obj.attackDamage; 
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor called" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if (energyPoint > 0 && health > 0)
    {
        this->energyPoint--;
        std::cout << "ClapTrap " << name << " attacks " << target << " , causing " << attackDamage << " points of damage!" << std::endl;   
    }
    if (health <= 0 )
    {
        std::cout << "ClapTrap " << name << " is Dead" << std::endl;
    }
    else if (energyPoint <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy point left to attack" << std::endl;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (health > 0)
    {
        if (this->health < (int)amount)
            this->health = 0;
        else
            this->health -= amount;
        std::cout << "ClapTrap " << name << " take damage " << amount << " , health became " << health << " HP" << std::endl;   
    }
    if (health <= 0 )
    {
        std::cout << "ClapTrap " << name << " is Dead" << std::endl;
    }
    else if (energyPoint <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy point left to attack" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoint > 0 && this->health > 0)
    {
        this->energyPoint--;
        this->health += amount;   
        std::cout << "ClapTrap " << name << "  repaired halth " << amount << " , health became  " << health << " HP" << std::endl;
    }
    if (health <= 0 )
    {
        std::cout << "ClapTrap " << name << " is Dead" << std::endl;
    }
    else if (energyPoint <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy point left to attack" << std::endl;
    }
}
