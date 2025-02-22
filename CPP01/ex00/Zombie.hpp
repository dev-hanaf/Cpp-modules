#pragma  once

# include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        void announce( void );
        Zombie();
        Zombie(std::string);
        ~Zombie();
};
void    randomChump(std::string name);
Zombie* newZombie(std::string name);