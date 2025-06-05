#pragma once

#include <exception>
#include <iostream>
#include <ostream>

class AForm;
class Bureaucrat
{
    private:
        const std::string  name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat&obj);
        Bureaucrat &operator=(const Bureaucrat&obj);
        ~Bureaucrat();
        
        const std::string &getName() const;
        const int &getGrade() const;
        
        // 1 is the highest and 150 the lowest
        void increment(); // --grade
        void decrement(); // ++grade
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
        void executeForm(AForm const &form) ;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);