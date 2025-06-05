#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>


class Form
{
    private:
        const std::string name;
        bool sign;
        const int gradeSign;
        const int gradeExecute;
    
    public:
    
        Form();
        Form(const std::string &name, int gradeSign, int gradeExecute );
        Form(const Form& obj);
        Form& operator=(const Form &obj);
        ~Form();


        bool    getSign() const;
        const std::string &getName() const;
        const int &getGradeSign() const;
        const int &getGradeExecute() const;
        

        void beSigned(const Bureaucrat &obj);
        
        
        void signForm(const Bureaucrat &obj);
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};


std::ostream &operator<<(std::ostream &os, const Form &obj);