#pragma  once

# include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        void setName(std::string &name);
        void announce( void );
        Zombie();
        Zombie(std::string);
        ~Zombie();
};
Zombie* zombieHorde(int N, std::string name );