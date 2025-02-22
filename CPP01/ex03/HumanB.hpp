#pragma  once

#include "Weapon.hpp"

class HumanB{
    private:
        std::string name;
        Weapon *weapon;
    public:
        HumanB(const std::string &);
        void setWeapon(Weapon &weapon);
        void attack();
};