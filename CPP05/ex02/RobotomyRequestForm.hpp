#pragma once

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;
        RobotomyRequestForm();

    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm& obj);
        RobotomyRequestForm &operator=(const RobotomyRequestForm& obj);
        ~RobotomyRequestForm();

        std::string getTarget() const;
        void  execute(Bureaucrat const & executor) const;  
        
};