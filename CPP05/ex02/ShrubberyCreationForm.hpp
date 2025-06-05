#pragma once

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm( const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& obj);
        ~ShrubberyCreationForm();

        std::string getTarget() const;
        void  execute(Bureaucrat const & executor) const;

};