#include "Bureaucrat.hpp"
#include <iterator>
#include <ostream>
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "grade is too low";
}

Bureaucrat::Bureaucrat() : name("ahanaf"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    grade = obj.getGrade();
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
    {
        grade = obj.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}


const std::string &Bureaucrat::getName() const
{
    return name;
}

const int &Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::increment()
{
    grade--;
    if (grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrement()
{
    grade++;
    if (grade > 150)
        throw GradeTooLowException();
}


void Bureaucrat::executeForm(AForm const &form)
{
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}