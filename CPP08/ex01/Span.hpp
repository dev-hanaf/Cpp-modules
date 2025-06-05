#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

class Span
{
    private:
        unsigned int N;
        std::vector<int> span;
        Span();
    public:
        Span(unsigned int N);
        Span(const Span &);
        Span& operator=(const Span &);
        ~Span();

        void addNumber(int);
        int shortestSpan();
        int longestSpan();
        
        void addManyNumbers(std::vector<int> &container)
        {
            for (std::vector<int>::iterator it = container.begin() ; it < container.end(); it++)
            {
                addNumber((*it));
            }
        }

        std::vector<int> &getSpan();
};