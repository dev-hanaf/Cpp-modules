#include "Zombie.hpp"

int main(void)
{
    Zombie *ptr;
    int N = 5;
    ptr = zombieHorde(N, "hanaf");

    for(int i=0; i < N; i++)
        ptr[i].announce();

    delete[] ptr;
}