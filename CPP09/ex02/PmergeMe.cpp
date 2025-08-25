#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <sstream>
#include <sys/time.h>
#include <vector>

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}


/* 
--------------- parse input ------------------- 
*/


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
            deckContainer.push_back(static_cast<int>(num));

        }
    }
    
    if (vectorContainer.empty()) {
        std::cerr << "Error: empty vector" << std::endl;
        return false;
    }
    
    return true;
}

/* 
--------------- merge insert sort Vector ------------------- 
*/
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
    // std::cout << "pair " << pair << std::endl;
	groupA.insert(groupA.begin(), pair);
	groupB.erase(find(groupB.begin(), groupB.end(), pair));
}


int PmergeMe::Jacobsthal( int idx) {
	if (idx == 0) return ( 1 );
	return ( (std::pow(2, idx) - std::pow(-1, idx)) / 3 );
}

std::vector<int> PmergeMe::calculationOrderOfInsertion( int size) {
	std::vector<int> order;
	std::vector<bool> used(size, false);
	int idx;
	int js = 2;
	while ((int) order.size() < size) {
		idx = Jacobsthal(js) - 1;
        // std::cout << "jacobsthal idx = " << idx << std::endl;
		while (idx >= size || used[idx] == true) {
			idx = (idx >= size) ? size - 1 : idx + 1;
            // std::cout << "idx >= size = " << idx << std::endl;

			if (idx >= size) {
                // std::cout << "idx >= size  true so idx = 0  /// idx == " << idx <<  std::endl;

				idx = 0;
				while (idx < size && used[idx] == true)
                {
                    // std::cout << "idx < size && used[idx] == true"<<  std::endl;
					++idx;
                }
            }
		}
		used[idx] = true;
		order.push_back(idx);
		++js;
	}
	return ( order );
}

void PmergeMe::BinaryInsertion(std::vector<int> &groupA,  int toAdd )
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
    sortPairs(arr); //  [<15, 4, 12, 18, 9>] => [15, 4, 18, 12, 9]]
    std::vector<int> groupA;
	std::vector<int> groupB;
    FormGroups(groupA, groupB, arr); // A: [15, 18, 9] | B: [4, 12]
    mergeInsertVector(groupA);
    insertPairOfFirstElm(arr, groupA, groupB);
    std::vector< int> insertionOrder= calculationOrderOfInsertion(groupB.size());
	unsigned int toInsert;
	for (unsigned int i = 0; i < groupB.size(); i++) {
		toInsert = insertionOrder[i];
		BinaryInsertion(groupA, groupB[toInsert]);
	}
	arr = groupA;
}

/* 
--------------- merge insert sort deque ------------------- 
*/

void sortDeck(std::deque<int> & deck)
{
    for (unsigned int i = 0; i < deck.size(); i = i + 2)
	{
		if (i + 1 < deck.size() && deck[i] < deck[i + 1])
			std::swap(deck[i], deck[i + 1]);
	}
}

void    groups(std::deque<int> &deck, std::deque<int> & a, std::deque<int> & b)
{
    unsigned int i = 0;
	while (i < deck.size()) {
		a.push_back(deck[i++]);
		if (i < deck.size())
			b.push_back(deck[i++]);
	}
}

void    putBinFirstA(std::deque<int> &deck, std::deque<int> & a, std::deque<int> & b)
{
    int lookFor;
	int pair;
	lookFor = a[0];
    
	for (unsigned int i = 0; i < deck.size(); i++)
	{
		if (deck[i] == lookFor)
		{
			if (i + 1 >= deck.size())
				return ;
			pair = deck[i + 1];
			break;
		}
	}
	a.insert(a.begin(), pair);
	b.erase(find(b.begin(), b.end(), pair));
}

std::deque<int> calOrderOfInsertion( int size) {
	std::deque<int> order;
	std::deque<bool> used(size, false);
	int idx;
	int js = 2;
	while ((int) order.size() < size) {
		idx = PmergeMe::Jacobsthal(js) - 1;
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

void BinaryInsertionDeck(std::deque<int> &groupA,  int toAdd )
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

void PmergeMe::mergeInsertDeque(std::deque<int>& deck)
{
    if (deck.size() <= 1)
        return; 
    
    sortDeck(deck);
    
    std::deque<int> a;
    std::deque<int> b;
    groups(deck, a, b);
    mergeInsertDeque(a);
    putBinFirstA(deck, a, b);
    std::deque< int> insertionOrder= calOrderOfInsertion(b.size());
	unsigned int toInsert;
	for (unsigned int i = 0; i < b.size(); i++) {
		toInsert = insertionOrder[i];
		BinaryInsertionDeck(a, b[toInsert]);
	}
    deck = a;
    
}


double PmergeMe::getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
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
    
    // deque sort
    startTime  = getTime();
    mergeInsertDeque(deckContainer);
    endTime = getTime();
    double dequeTime = endTime - startTime;
    printSequence(vectorContainer, "vector After: ");
    printSequence(deckContainer, "Deck After: ");
    displayResults(vectorTime, dequeTime, deckContainer.size());

}