#pragma once

#include <exception>
#include <iostream>
#include <vector>

class PmergeMe
{
    private:
        std::vector<int> vectorContainer;
        void printSequence(const std::vector<int>& arr, const std::string& prefix) const;
        void mergeInsertVector(std::vector<int>& arr);
    public:
        PmergeMe();
        ~PmergeMe();
        bool parseInput(int ac, char** av);
        void sortAndTime();



};