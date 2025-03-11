#pragma once

#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &);
        Animal& operator=(const Animal&);
        virtual ~Animal();
        virtual void makeSound() const = 0;
        const std::string getType() const;
};