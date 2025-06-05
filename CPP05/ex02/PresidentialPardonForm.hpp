#pragma once

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm& obj);
        PresidentialPardonForm &operator=(const PresidentialPardonForm& obj);
        ~PresidentialPardonForm();

        std::string getTarget() const;
        void  execute(Bureaucrat const & executor) const;  
};