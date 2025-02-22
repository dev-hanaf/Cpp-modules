#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &type): name(name), weapon(type){}

void HumanA::attack()
{
    std::cout <<  name << " attacks with their " << weapon.getType() << std::endl;
}