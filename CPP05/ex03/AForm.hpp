#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>


class AForm
{
    private:
        const std::string name;
        bool sign;
        const int gradeSign;
        const int gradeExecute;
    
    public:
    
        AForm();
        AForm(const std::string &name, int gradeSign, int gradeExecute );
        AForm(const AForm& obj);
        AForm& operator=(const AForm &obj);
        virtual ~AForm();


        bool    getSign() const;
        const std::string &getName() const;
        const int &getGradeSign() const;
        const int &getGradeExecute() const;
        

        void beSigned(const Bureaucrat &obj);
        void signForm(const Bureaucrat &obj);
        
        virtual void execute(Bureaucrat const & executor) const = 0;
        
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

        class NotSigned: public std::exception {
        
            public:
                const char* what() const throw();
        };

};


std::ostream &operator<<(std::ostream &os, const AForm &obj);