#pragma once

#include <iostream>
#include <map>
#include <exception>
#include <sstream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
    private:
        std::map<std::string , float > _btcMap;
        std::ifstream file;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void fileExist(const char *str);
        class MyCustomException : public std::exception
        {
            private:
                const char * _msg;
            public:
                MyCustomException(const char *msg);
                const char * what() const throw();
        };

        void fetchFileData();
        void parseInput();
        void diplayMap();

};