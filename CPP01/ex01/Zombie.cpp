#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void Zombie::setName(std::string &name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
   std::cout << "GoodBey " << this->name << std::endl;
}

Zombie::Zombie(){};