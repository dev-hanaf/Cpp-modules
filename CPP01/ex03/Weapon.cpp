#include "Weapon.hpp"

const std::string &Weapon::getType(void)
{
    return this->type;
}

void Weapon::setType(const std::string &type)
{
    this->type = type;
}

Weapon::Weapon(const std::string &type) : type(type){}

Weapon::Weapon(){};

Weapon::~Weapon(){};
