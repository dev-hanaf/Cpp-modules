#pragma once

#include "AForm.hpp"
#include <iostream>

class Intern
{
    private:
    
    public:
        Intern();
        Intern(const Intern& obj);
        Intern &operator=(const Intern&obj);
        ~Intern();

        AForm *makeForm(const std::string , const std::string );
};

