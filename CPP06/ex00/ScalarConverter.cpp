#include "ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <string>


bool isChar(std::string c)
{
    if (c.length() == 1)
    {
        if (isprint(c[0]) && !isdigit(c[0]))
            return true;
    }
    return false;
}

bool isInt(std::string input)
{
    int i =0;
    if (input[i] == '-' || input[i] == '+')
        i++;
    for(; i < static_cast<int>(input.length()); i++)
    {
        if (!isdigit(input[i]))
            return false;
    }
    return true;
}

bool isFloat(std::string input)
{
    if(input == "-nanf" || input =="+nanf")
        return false;
    char *end;
    std::strtof(input.c_str(), &end);
    if (*end == 'f' && *(end + 1) == '\0')
    { 
        return true; 
    }
    return false;
}

bool isDouble(std::string input)
{
    if(input == "-nan" || input =="+nan")
        return false;
    char *end;
    std::strtod(input.c_str(), &end);
    if (*end == '\0')
    { 
        return true; 
    }
    return false;
}

void printChar(char c)
{
    std::cout << "char: " << static_cast<char>(c) << std::endl; 
    std::cout << "int: " << static_cast<int>(c) << std::endl; 
    std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::setprecision(2) << static_cast<double>(c) << std::endl; 
}

void printFloat(std::string input)
{
    double f = std::strtod(input.c_str(), NULL);
    if (f < 32 || f > 126)
        std::cout << "char: Non displayable" << std::endl;
    else 
        std::cout << "char: " << static_cast<char>(f) << std::endl; 
    if (f > INT_MAX || f < INT_MIN)
        std::cout << "int: Non displayable" << std::endl;
    else 
        std::cout << "int: " << static_cast<int>(f) << std::endl; 
    std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(f) << "f" << std::endl;
    std::cout << "double: " << std::fixed  << std::setprecision(2) << static_cast<double>(f) << std::endl; 
}

void printDouble(std::string input)
{
    double d = std::strtod(input.c_str(), NULL);
    if (d < 32 || d > 126)
        std::cout << "char: Non displayable" << std::endl;
    else 
        std::cout << "char: " << static_cast<char>(d) << std::endl; 
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: Non displayable" << std::endl;
    else 
        std::cout << "int: " << static_cast<int>(d) << std::endl; 
    std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << std::setprecision(2) << static_cast<double>(d) << std::endl; 
}

void printInt(std::string input)
{
    double d = std::strtod(input.c_str(),NULL);
    if (d > INT_MAX || d < INT_MIN)
    {
        std::cout << "type conversion is impossible" << std::endl;
        return;
    }
    if (d < 32 || d > 126)
        std::cout << "char: Non displayable" << std::endl;
    else 
        std::cout << "char: " << static_cast<char>(d) << std::endl; 
    std::cout << "int: " << static_cast<int>(d) << std::endl; 
    std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(d) << "f" << std::endl; 
    std::cout << "double: " << std::setprecision(2) << static_cast<double>(d) << std::endl; 
}

void ScalarConverter::convert(std::string input)
{
    if (input == "-inff" || input == "+inff" || input == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;                                  
    }
    else if (input == "-inf" || input == "+inf" || input == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
    }
    else if(isChar(input))
        printChar(input[0]);
    else if (isInt(input))
        printInt(input);
    else if (isFloat(input))
        printFloat(input);
    else if (isDouble(input))
        printFloat(input);
    else
        std::cout << "Bad Argument" << std::endl;
}
