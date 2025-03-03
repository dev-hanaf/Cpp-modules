#include "ScavTrap.hpp"


int main(void)
{
    // Test ScavTrap construction and destruction
    {
        std::string name = "Scavvy";
        ScavTrap scav1;
        scav1.attack("Bandit");
        scav1.takeDamage(30);
        scav1.beRepaired(20);
        scav1.guardGate();
    }

    // // Test copy constructor and assignment operator
    // {

    //     std::string name = "Scavvy2";
    //     ScavTrap scav2(name);
    //     ScavTrap scav3(scav2); // Copy constructor
    //     ScavTrap scav4;
    //     scav4 = scav3; // Copy assignment operator
    // }

    return 0;
}