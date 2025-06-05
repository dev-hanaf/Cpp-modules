#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential", 72, 45), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj)
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    AForm::operator=(obj);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}


std::string PresidentialPardonForm::getTarget() const
{
    return target;
}


void  PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if(executor.getGrade() > getGradeExecute())
        throw Bureaucrat::GradeTooLowException();
    else if (getSign() == false)
        throw AForm::NotSigned();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
