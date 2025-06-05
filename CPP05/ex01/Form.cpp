#include "Form.hpp"
#include <exception>
#include <ostream>

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form Grade Too Low";
}

Form::Form() : name("F1"), sign(false), gradeSign(50), gradeExecute(100)
{

}

Form::Form(const std::string& name, int gradeSign, int gradeExecute)
    : name(name), sign(false), gradeSign(gradeSign), gradeExecute(gradeExecute) 
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException(); 
}

Form::Form(const Form &obj) : name(obj.name), sign(obj.sign), gradeSign(obj.gradeSign), gradeExecute(obj.gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();
}

Form & Form::operator=(const Form &obj)
{
    if (this != &obj)
    {
        sign = obj.sign;
    }
    return *this;
}

Form::~Form()
{
}


bool Form::getSign() const
{
    return sign;
}

const std::string &Form::getName() const
{
    return name;
}
const int &Form::getGradeSign() const
{
    return gradeSign;
}
const int &Form::getGradeExecute() const
{
    return gradeExecute;
}

void Form::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() <= gradeSign)
        sign = true;
    else
        throw Form::GradeTooLowException();
}


void Form::signForm(const Bureaucrat &obj)
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

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << "Form " << obj.getName() 
       << ", status: " << (obj.getSign() ? "signed" : "unsigned")
       << ", grade required to sign: " << obj.getGradeSign()
       << ", grade required to execute: " << obj.getGradeExecute();
    return os;
}