#include "DiamondTrap.hpp"
#include "FragTrap.hpp"


int main(void)
{
   {
        DiamondTrap frag1("hanaf");
        frag1.attack("Bandit");
        frag1.takeDamage(30);
        frag1.beRepaired(20);
        frag1.highFivesGuys();
        frag1.whoAmI();
    }

    return 0;
}