#include "RPN.hpp"
#include <sstream>

RPN::RPN() {}
RPN::~RPN() {}


RPN::MyException::MyException(const char *msg)
{
    _msg = msg;
}

const char * RPN::MyException::what() const throw()
{
    return _msg;
}



bool RPN::isOperator(const std::string& token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}


bool RPN::isNumber(const std::string& token) const {
    if (token.empty()) return false;
    
    if (token.length() == 1) {
        return (token[0] >= '0' && token[0] <= '9');
    }
    
    if (token.length() == 2 && token[0] == '-') {
        return (token[1] >= '0' && token[1] <= '9');
    }
    
    return false;
}


int RPN::performOperation(int a, int b, const std::string& op) const {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) {
            throw MyException("Division by zero");
        }
        return a / b;
    }
    throw MyException("Unknown operator");
}

int RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;
    while (!_stack.empty()) {
        _stack.pop();
    }
    
    while (iss >> token) {
        if (isNumber(token)) {
            int num;
            std::stringstream ss(token);
            ss >> num;
            _stack.push(num);
        }
        else if (isOperator(token)) {
            if (_stack.size() < 2) {
                throw MyException("Error: insufficient operands");
            }            
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            
            int result = performOperation(a, b, token);
            _stack.push(result);
        }
        else {
            throw MyException("Error");
        }
    }
    
    if (_stack.size() != 1) {
        throw MyException("Error: invalid expression");
    }
    
    return _stack.top();
}