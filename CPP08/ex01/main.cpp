#include "Span.hpp"
#include <vector>


int main()
{
    Span sp = Span(50);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    // std::vector<int>test(5, 5);
    // // for (int i = 0 ; i < 10; i++)
    // //     test.push_back(i);
    // // for(std::vector<int> it =)
    // sp.addManyNumbers(test);

    // for (std::vector<int>::iterator it = sp.getSpan().begin(); it < sp.getSpan().end(); it++)
    //     std::cout << (*it) << std::endl;


    // std::cout << "//////////////////////////// shortest span ///////////////////////////\n";
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << "//////////////////////////// longest span ///////////////////////////\n";
    // std::cout << sp.longestSpan() << std::endl;
    
    return 0;
}