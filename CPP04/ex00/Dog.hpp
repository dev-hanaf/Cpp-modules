#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog &);
        Dog& operator=(const Dog&);
        ~Dog();
        void makeSound() const;
};