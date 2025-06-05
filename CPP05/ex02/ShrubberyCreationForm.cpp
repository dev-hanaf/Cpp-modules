#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    AForm::operator=(obj);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}


void  ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(executor.getGrade() > getGradeExecute())
        throw Bureaucrat::GradeTooLowException();
    else if (getSign() == false)
        throw AForm::NotSigned();

    std::ofstream outfile(this->getTarget().append("_shrubbery").c_str());
    if (outfile.is_open())
    {
        outfile << "       _-_\n"
            << "    /~~   ~~\\\n"
            << " /~~         ~~\\\n"
            << "{               }\n"
            << " \\  _-     -_  /\n"
            << "   ~  \\\\ //  ~\n"
            << "_- -   | | _- _\n"
            << "  _ -  | |   -_\n"
            << "      // \\\\\n";
        outfile.close();
    }
}  

