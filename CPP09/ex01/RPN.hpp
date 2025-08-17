#pragma once

#include <iostream>
#include <exception>
#include <stack>
#include <sstream>
#include <string>

class RPN
{
    private:
        std::stack<int>_stack;
        bool isOperator(const std::string& token) const;
        bool isNumber(const std::string& token) const;
        int performOperation(int a, int b, const std::string& op) const;

    public:
        RPN();
        ~RPN();

        int evaluate(const std::string &expression);

        class MyException : public std::exception
        {
            private:
                const char *_msg;
            public:
                MyException(const char *msg);
                const char * what() const throw();
        };
};