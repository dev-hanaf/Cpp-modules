#include "Zombie.hpp"

int main(void)
{
    Zombie *ptrObj;

    ptrObj = newZombie("ahanaf");
    ptrObj->announce();

    randomChump("Zombie");
 
    delete ptrObj;
}