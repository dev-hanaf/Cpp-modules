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
        void sortPairs(std::vector<int> &arr);

        void FormGroups(std::vector<int> &groupA, std::vector<int> &groupB, std::vector<int> &arr);
        void insertPairOfFirstElm(std::vector<int>& arr, std::vector<int> &groupA,std::vector<int>& groupB);
        
        double getTime();

        void displayResults(double vectorTime, double dequeTime, int size);



    public:
        PmergeMe();
        ~PmergeMe();
        bool parseInput(int ac, char** av);
        void sortAndTime();



};