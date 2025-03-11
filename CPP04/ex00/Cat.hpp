#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat &);
        Cat& operator=(const Cat&);
        ~Cat();
        void makeSound() const;
};