#include "Span.hpp"
#include <climits>


Span::Span(unsigned int N) : N(N)
{
}

Span::Span(const Span &obj)
{
    N = obj.N;
    for (size_t i=0; i < N; i++)
        span.push_back(obj.span[i]);
}

Span & Span::operator=(const Span &obj)
{
    if (this != &obj)
    {
        N = obj.N;
        for (size_t i=0; i < N; i++)
            span.push_back(obj.span[i]);
    }
    return *this;
}

Span::~Span() {}


void Span::addNumber(int num)
{
    if (span.size() < N)
    {
        span.push_back(num);
        return;
    }
    throw std::out_of_range("Cannot add number - Span is already full");
}


int Span::shortestSpan()
{
    if (span.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");
    std::vector<int> sorted = span;
    std::sort(sorted.begin(), sorted.end());

    int min_diff = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) 
    {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < min_diff)
        {
            min_diff = diff;
            if (min_diff == 0)
                return 0;
        }
    }
    return min_diff;
}

int Span::longestSpan()
{
    if (span.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");
    std::vector<int> tmp = span;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

std::vector<int> &Span::getSpan()
{
    return span;
}