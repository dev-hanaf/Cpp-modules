#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::MyCustomException::MyCustomException(const char *msg)
{
    _msg = msg;
}

const char *BitcoinExchange::MyCustomException::what() const throw()
{
    return _msg;   
}


void BitcoinExchange::fileExist(const char *str)
{
    file.open(str);
    if (!file.is_open())
        throw MyCustomException("Error: failed to open input file");
}    




void BitcoinExchange::fetchFileData()
{
    std::ifstream data("data.csv");
    if (!data.is_open())
        throw MyCustomException("Error: failed to open database file");

    std::string line;
    char dlm;
    if (std::getline(data, line))
    {
        if (line.empty())
            throw MyCustomException("Error: first line empty");
        if (line.find("date") != 0)
            throw MyCustomException("Error: invalid format line date");
        line = line.substr(4);
        if (!isalpha(line[0])) dlm = line[0];
        line = line.substr(1);
        if (line.find("exchange_rate") != 0 || line.size() != 13)
            throw MyCustomException("Error: invalid format line exchange_rate");
    }
    while(std::getline(data, line))
    {
        if (line.empty())
            throw MyCustomException("Error: line empty");
        std::string key, value;

        std::stringstream ss(line);
        std::getline(ss, key, dlm);
        std::getline(ss, value, '\n');
        if (key.empty())
            throw MyCustomException("Error: key empty");
        if (value.empty())
            throw MyCustomException("Error: value empty");
        
        struct tm tm;
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (strptime(key.c_str(), "%Y-%m-%d", &tm))
        {
            int year  = tm.tm_year + 1900;
            int month = tm.tm_mon + 1; // tm_mon is 0-based
            int day   = tm.tm_mday;
            
            if (year < 2009)
                throw MyCustomException("Error: blockchain officially began in 2009");
            if (month == 2) {
                bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
                if (leap) daysInMonth[2] = 29;
            }
            if (day > daysInMonth[month])
                throw MyCustomException("Error: corrupted data in database");
        }
        float exchange_rate;
        std::stringstream oss(value);
        oss >> exchange_rate;
        if (oss.fail() || !oss.eof()) {
            throw MyCustomException("Error: corrupted data in database");
        }
        _btcMap[key] = exchange_rate;
    }
    
}

std::string trim(const std::string &str)
{
    const std::string whitespace = " \t\n\r\f\v";

    size_t start = str.find_first_not_of(whitespace);
    if (start == std::string::npos)
        return "";

    size_t end = str.find_last_not_of(whitespace);

    return str.substr(start, end - start + 1);
}

void BitcoinExchange::parseInput()
{
    std::string line;
    if (std::getline(file, line))
    {
        if (line.empty())
            throw MyCustomException("Error: first line empty");
        if (line.find("date ") != 0)
            throw MyCustomException("Error: invalid format line date");
        line = line.substr(5);
        if (line[0] != '|') 
            throw MyCustomException("Error: invalid delimiter excpected |");
        line = line.substr(2);
        if (line.find("value") != 0 || line.size() != 5)
            throw MyCustomException("Error: invalid format line value");
        line = line.substr(5);
    }
    while(std::getline(file, line))
    {
        if (line.empty()) {
            std::cerr << "Error: line empty" << std::endl;
            continue;
        }
        std::string key, value;

        std::stringstream ss(line);
        std::getline(ss, key, '|');
        std::getline(ss, value, '\n');
        key = trim(key);
        value = trim(value);
        if (key.empty()) {
            std::cerr << "Error: key empty" << std::endl;
            continue;
        }
        if (value.empty()) {
            std::cerr << "Error: bad input => " << key << std::endl;
            continue;
        }
        
        struct tm tm;
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (strptime(key.c_str(), "%Y-%m-%d", &tm))
        {
            int year  = tm.tm_year + 1900;
            int month = tm.tm_mon + 1; // tm_mon is 0-based
            int day   = tm.tm_mday;
            
            if (year < 2009) {
                std::cerr << "Error: bad input => " << key << std::endl;
                continue;
            }
            if (month == 2) {
                bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
                if (leap) daysInMonth[2] = 29;
            }
            if (day > daysInMonth[month]) {
                std::cerr << "Error: bad input => " << key << std::endl;
                continue;
            }
        }
        
        float f_value;
        std::stringstream oss(value);
        oss >> f_value;
        if (oss.fail() || !oss.eof()) {
            std::cerr << "Error: bad input => " << value << std::endl;
            continue;
        }
        else if (f_value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        else if (f_value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string, float >::iterator it = _btcMap.lower_bound(key);
        if (it->first == key)
        {
            std::cout << key << " => " << f_value << " = " <<  (float)(it->second * f_value) << std::endl;   
        }
        else
        {
            it--;
            std::cout << key << " => " << f_value << " = " <<  (float)(it->second * f_value) << std::endl;   
        }
    }
}

void BitcoinExchange::diplayMap()
{
    for (std::map<std::string, float>::const_iterator it = _btcMap.begin(); it != _btcMap.end(); it++)
    {
        std::cout << "key =|" << it->first << "|value =|" << it->second << "|"<< std::endl; 
    }
}