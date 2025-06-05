#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    AForm::operator=(obj);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}


std::string RobotomyRequestForm::getTarget() const
{
    return target;
}



void  RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(executor.getGrade() > getGradeExecute())
        throw Bureaucrat::GradeTooLowException();
    else if (getSign() == false)
        throw AForm::NotSigned();

    std::cout << "Drilling noises... Bzzzzzzzt!" << std::endl;
    srand(time(NULL));
    int random = rand() % 2;
    if (random == 1)
		std::cout << "BRRRRRRRRRRRRRR\n" << this->getTarget() << " was robotomized" << std::endl;
    else
		std::cout << "Robotomy failed" << std::endl;
}
