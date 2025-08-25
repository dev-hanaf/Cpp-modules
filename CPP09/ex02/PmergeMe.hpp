#pragma once

#include <deque>
#include <exception>
#include <iostream>
#include <vector>

class PmergeMe
{
    private:
        std::vector<int> vectorContainer;
        std::deque<int> deckContainer;

        void displayResults(double vectorTime, double dequeTime, int size);
        
        void mergeInsertVector(std::vector<int>& arr);
        void sortPairs(std::vector<int> &arr);
        void FormGroups(std::vector<int> &groupA, std::vector<int> &groupB, std::vector<int> &arr);
        void insertPairOfFirstElm(std::vector<int>& arr, std::vector<int> &groupA,std::vector<int>& groupB);
        std::vector<int> calculationOrderOfInsertion( int size);
        void BinaryInsertion(std::vector<int> &groupA,  int toAdd );
        
        double getTime();        
        void mergeInsertDeque(std::deque<int>& arr);
        template<class Container>
        void printSequence(Container& arr, const std::string& prefix) {
            std::cout << prefix;
            for (size_t i = 0; i < arr.size() && i < 20; ++i) {
                std::cout << arr[i] << " ";
            }
            if (arr.size() > 20) {
                std::cout << "[...]";
            }
            std::cout << std::endl;
        }
        
    public:
        static int Jacobsthal( int idx);
        PmergeMe();
        ~PmergeMe();
        bool parseInput(int ac, char** av);
        void sortAndTime();



};