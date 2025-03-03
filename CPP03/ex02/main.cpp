#include "FragTrap.hpp"


int main(void)
{
   {
        FragTrap frag1("hanaf");
        frag1.attack("Bandit");
        frag1.takeDamage(30);
        frag1.beRepaired(20);
        frag1.highFivesGuys();
    }

    // Test default constructor
    {
        FragTrap frag2;
        frag2.attack("Enemy");
        frag2.highFivesGuys();
    }

    return 0;

    return 0;
}