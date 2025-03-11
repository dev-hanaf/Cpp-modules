#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat &);
        Cat& operator=(const Cat&);
        ~Cat();
        void makeSound() const;
};