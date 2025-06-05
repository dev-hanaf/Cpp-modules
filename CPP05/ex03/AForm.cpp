#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm Grade Too Low";
}

const char* AForm::NotSigned::what() const throw()
{
    return "Not Signed";
}

AForm::AForm() : name("F1"), sign(false), gradeSign(50), gradeExecute(100)
{

}

AForm::AForm(const std::string& name, int gradeSign, int gradeExecute)
    : name(name), sign(false), gradeSign(gradeSign), gradeExecute(gradeExecute) 
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException(); 
}

AForm::AForm(const AForm &obj) : name(obj.name), sign(obj.sign), gradeSign(obj.gradeSign), gradeExecute(obj.gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();
}

AForm & AForm::operator=(const AForm &obj)
{
    if (this != &obj)
    {
        sign = obj.sign;
    }
    return *this;
}

AForm::~AForm()
{
}


bool AForm::getSign() const
{
    return sign;
}

const std::string &AForm::getName() const
{
    return name;
}
const int &AForm::getGradeSign() const
{
    return gradeSign;
}
const int &AForm::getGradeExecute() const
{
    return gradeExecute;
}

void AForm::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() <= gradeSign)
        sign = true;
    else
        throw AForm::GradeTooLowException();
}


void AForm::signForm(const Bureaucrat &obj)
{
    try
    {
        beSigned(obj);
        std::cout << obj.getName() << " signed " << getName();
    }
    catch(std::exception &e)
    {
        std::cout << obj.getName() << " couldn’t sign " << getName() << "  because " << e.what() <<  std::endl;
    }
}



std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
    os << "AForm " << obj.getName() 
       << ", status: " << (obj.getSign() ? "signed" : "unsigned")
       << ", grade required to sign: " << obj.getGradeSign()
       << ", grade required to execute: " << obj.getGradeExecute();
    return os;
}