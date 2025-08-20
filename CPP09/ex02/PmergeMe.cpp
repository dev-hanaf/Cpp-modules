#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <sstream>
#include <vector>
#include <sys/time.h>

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}


double PmergeMe::getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

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


void PmergeMe::sortPairs(std::vector<int> &arr)
{
    for (unsigned int i = 0; i < arr.size(); i = i + 2)
	{
		if (i + 1 < arr.size() && arr[i] < arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
	}
}


void PmergeMe::FormGroups(std::vector<int> &groupA, std::vector<int> &groupB, std::vector<int> &arr)
{
    unsigned int i = 0;
	while (i < arr.size()) {
		groupA.push_back(arr[i++]);
		if (i < arr.size())
			groupB.push_back(arr[i++]);
	}
}


void PmergeMe::insertPairOfFirstElm(std::vector<int>& arr, std::vector<int> &groupA,std::vector<int>& groupB) {
	int lookFor;
	int pair;
	lookFor = groupA[0];
    
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == lookFor)
		{
			if (i + 1 >= arr.size())
				return ;
			pair = arr[i + 1];
			break;
		}
	}
	groupA.insert(groupA.begin(), pair);
	groupB.erase(find(groupB.begin(), groupB.end(), pair));
}


int Jacobsthal( int idx) {
	if (idx == 0) return ( 1 );
	return ( (std::pow(2, idx) - std::pow(-1, idx)) / 3 );
}

std::vector<int> calculationOrderOfInsertion( int size) {
	std::vector<int> order;
	std::vector<bool> used(size, false);
	int idx;
	int js = 2;
	while ((int) order.size() < size) {
		idx = Jacobsthal(js) - 1;
		while (idx >= size || used[idx] == true) {
			idx = (idx >= size) ? size - 1 : idx + 1;
			if (idx >= size) {
				idx = 0;
				while (idx < size && used[idx] == true)
					++idx;
			}
		}
		used[idx] = true;
		order.push_back(idx);
		++js;
	}
	return ( order );
}


void BinaryInsertion(std::vector<int> &groupA,  int toAdd )
{
	int left = 0, right = groupA.size() - 1;
	unsigned int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (toAdd > groupA[mid]) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	groupA.insert(groupA.begin() + left, toAdd);
}

void PmergeMe::mergeInsertVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return;

    
    sortPairs(arr); //  [15, 4, 12, 18, 9] => [15, 4, 18, 12, 9]]
    // printSequence(arr , "sort pairs: ");

    std::vector<int> groupA;
	std::vector<int> groupB;

    FormGroups(groupA, groupB, arr); // A: [15, 18, 9] | B: [4, 12]
    // printSequence(groupA, "group A: ");
    // printSequence(groupB , "group B: ");

    mergeInsertVector(groupA);
    // std::cout << "\n";

    // printSequence(groupA, "group A after recursion end: ");
    // printSequence(groupB, "group B after recursion end: ");

    insertPairOfFirstElm(arr, groupA, groupB);
    // printSequence(groupA, "group A after inser pair of first element : ");
    // printSequence(groupB, "group B after inser pair of first element : ");

    std::vector< int> insertionOrder= calculationOrderOfInsertion(groupB.size());
    // printSequence(insertionOrder , "insertion order : ");

	unsigned int toInsert;
	for (unsigned int i = 0; i < groupB.size(); i++) {
		toInsert = insertionOrder[i];
		BinaryInsertion(groupA, groupB[toInsert]);
	}
	arr = groupA;

}


void PmergeMe::displayResults(double vectorTime, double dequeTime, int size) {
    std::cout << "Time to process a range of " << size << " elements with std::vector : " 
              << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::deque : " 
              << dequeTime << " us" << std::endl;
}

void PmergeMe::sortAndTime()
{
    double startTime = getTime();
    printSequence(vectorContainer, "Before: ");
    mergeInsertVector(vectorContainer);;
    double endTime = getTime();
    double vectorTime = endTime - startTime;
    printSequence(vectorContainer, "After: ");
    displayResults(vectorTime, vectorTime, vectorContainer.size());

    
}