#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <sstream>
#include <vector>


PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

void PmergeMe::printSequence(const std::vector<int>& arr, const std::string& prefix) const {
    std::cout << prefix;
    for (size_t i = 0; i < arr.size() && i < 20; ++i) {
        std::cout << arr[i] << " ";
    }
    if (arr.size() > 20) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

bool PmergeMe::parseInput(int ac, char** av)
{
       for (int i = 1; i < ac; ++i) {
        std::stringstream ss(av[i]);
        std::string token;
        
        while (ss >> token) {
            if (token.empty()) continue;
            
            if (token[0] == '-') {
                std::cerr << "Error: negative number" << std::endl;
                return false;
            }
            
            char* endptr;
            long num = std::strtol(token.c_str(), &endptr, 10);
            
            if (*endptr != '\0' || num <= 0 || num > 2147483647) {
                std::cerr << "Error: bad number" << std::endl;
                return false;
            }
            
            vectorContainer.push_back(static_cast<int>(num));
        }
    }
    
    if (vectorContainer.empty()) {
        std::cerr << "Error: empty vector" << std::endl;
        return false;
    }
    
    return true;
}

void PmergeMe::mergeInsertVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return;
}


void PmergeMe::sortAndTime()
{
    printSequence(vectorContainer , "Before: ");
    mergeInsertVector(vectorContainer);
    
}















































// void PmergeMe::parse(const std::string & str)
// {

//     std::istringstream iss(str);
//     int num;
//     while(iss >> num)
//     {
//         vectorContainer.push_back(num);
//     }

//     display(vectorContainer);
// }      


// void sortvectorContaineraypairs(std::vector<int > &vectorContainer, std::vector<int> &winners, std::vector<int > &losers)
// {
//     std::sort(vectorContainer.begin(), vectorContainer.end());
//     for(size_t i = 0; i < vectorContainer.size(); i++)
//     {
//         if (vectorContainer[i] && vectorContainer[i+1])
//         {
//             if (vectorContainer[i] < vectorContainer[i+1])
//             {
//                 winners.push_back(vectorContainer[i+1]);
//                 losers.push_back(vectorContainer[i]);
//                 i++;
//             }
//             else
//             {
//                 winners.push_back(vectorContainer[i]);
//                 losers.push_back(vectorContainer[i +1]);
//                 i++;
//             }
//         }
//         else
//             winners.push_back(vectorContainer[i++]);
//     }
// }




// void PmergeMe::winners()
// {
//     if (vectorContainer.size() < 2)
//         return ;

//     std::vector<int> winners;
//     std::vector<int> losers;


//     sortvectorContaineraypairs(vectorContainer, winners, losers);
//     std::cout << "sorted vectorContaineray" << std::endl;

//     display(vectorContainer);

//     std::cout << "winners" << std::endl;
//     display(winners);
//     std::cout << "losers" << std::endl;
//     display(losers);

// }



