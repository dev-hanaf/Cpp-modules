#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

double PmergeMe::getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

bool PmergeMe::parseInput(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return false;
    }
    
    for (int i = 1; i < argc; ++i) {
        std::stringstream ss(argv[i]);
        std::string token;
        
        while (ss >> token) {
            if (token.empty()) continue;
            
            // Check for negative numbers
            if (token[0] == '-') {
                std::cerr << "Error" << std::endl;
                return false;
            }
            
            // Convert to integer
            char* endptr;
            long num = std::strtol(token.c_str(), &endptr, 10);
            
            if (*endptr != '\0' || num <= 0 || num > 2147483647) {
                std::cerr << "Error" << std::endl;
                return false;
            }
            
            _vectorContainer.push_back(static_cast<int>(num));
            _dequeContainer.push_back(static_cast<int>(num));
        }
    }
    
    if (_vectorContainer.empty()) {
        std::cerr << "Error" << std::endl;
        return false;
    }
    
    return true;
}

bool PmergeMe::processInput(int argc, char** argv) {
    return parseInput(argc, argv);
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

// Vector implementation
int PmergeMe::binarySearchVector(const std::vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

void PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int pos = binarySearchVector(arr, left, i - 1, key);
        
        // Shift elements
        for (int j = i; j > pos; --j) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = key;
    }
}

void PmergeMe::mergeInsertVector(std::vector<int>& arr, int left, int right) {
    if (right - left < 10) {
        insertionSortVector(arr, left, right);
        return;
    }
    
    // Create pairs and sort them
    std::vector<std::pair<int, int> > pairs;
    int i;
    for (i = left; i + 1 <= right; i += 2) {
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        } else {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
    }
    
    // Handle odd element
    int oddElement = -1;
    bool hasOdd = false;
    if (i == right) {
        oddElement = arr[right];
        hasOdd = true;
    }
    
    // Sort pairs by their larger element
    for (size_t j = 0; j < pairs.size(); ++j) {
        for (size_t k = j + 1; k < pairs.size(); ++k) {
            if (pairs[j].second > pairs[k].second) {
                std::pair<int, int> temp = pairs[j];
                pairs[j] = pairs[k];
                pairs[k] = temp;
            }
        }
    }
    
    // Create main chain with larger elements
    std::vector<int> mainChain;
    std::vector<int> pendingElements;
    
    for (size_t j = 0; j < pairs.size(); ++j) {
        mainChain.push_back(pairs[j].second);
        pendingElements.push_back(pairs[j].first);
    }
    
    // Insert first small element
    if (!pendingElements.empty()) {
        int pos = binarySearchVector(mainChain, 0, mainChain.size() - 1, pendingElements[0]);
        mainChain.insert(mainChain.begin() + pos, pendingElements[0]);
    }
    
    // Insert remaining elements using Jacobsthal sequence
    for (size_t j = 1; j < pendingElements.size(); ++j) {
        int pos = binarySearchVector(mainChain, 0, mainChain.size() - 1, pendingElements[j]);
        mainChain.insert(mainChain.begin() + pos, pendingElements[j]);
    }
    
    // Insert odd element if exists
    if (hasOdd) {
        int pos = binarySearchVector(mainChain, 0, mainChain.size() - 1, oddElement);
        mainChain.insert(mainChain.begin() + pos, oddElement);
    }
    
    // Copy back to original array
    for (size_t j = 0; j < mainChain.size(); ++j) {
        arr[left + j] = mainChain[j];
    }
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;
    mergeInsertVector(arr, 0, arr.size() - 1);
}

// Deque implementation
int PmergeMe::binarySearchDeque(const std::deque<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int pos = binarySearchDeque(arr, left, i - 1, key);
        
        // Shift elements
        for (int j = i; j > pos; --j) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = key;
    }
}

void PmergeMe::mergeInsertDeque(std::deque<int>& arr, int left, int right) {
    if (right - left < 10) {
        insertionSortDeque(arr, left, right);
        return;
    }
    
    // Create pairs and sort them
    std::deque<std::pair<int, int> > pairs;
    int i;
    for (i = left; i + 1 <= right; i += 2) {
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        } else {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
    }
    
    // Handle odd element
    int oddElement = -1;
    bool hasOdd = false;
    if (i == right) {
        oddElement = arr[right];
        hasOdd = true;
    }
    
    // Sort pairs by their larger element
    for (size_t j = 0; j < pairs.size(); ++j) {
        for (size_t k = j + 1; k < pairs.size(); ++k) {
            if (pairs[j].second > pairs[k].second) {
                std::pair<int, int> temp = pairs[j];
                pairs[j] = pairs[k];
                pairs[k] = temp;
            }
        }
    }
    
    // Create main chain with larger elements
    std::deque<int> mainChain;
    std::deque<int> pendingElements;
    
    for (size_t j = 0; j < pairs.size(); ++j) {
        mainChain.push_back(pairs[j].second);
        pendingElements.push_back(pairs[j].first);
    }
    
    // Insert first small element
    if (!pendingElements.empty()) {
        int pos = binarySearchDeque(mainChain, 0, mainChain.size() - 1, pendingElements[0]);
        mainChain.insert(mainChain.begin() + pos, pendingElements[0]);
    }
    
    // Insert remaining elements
    for (size_t j = 1; j < pendingElements.size(); ++j) {
        int pos = binarySearchDeque(mainChain, 0, mainChain.size() - 1, pendingElements[j]);
        mainChain.insert(mainChain.begin() + pos, pendingElements[j]);
    }
    
    // Insert odd element if exists
    if (hasOdd) {
        int pos = binarySearchDeque(mainChain, 0, mainChain.size() - 1, oddElement);
        mainChain.insert(mainChain.begin() + pos, oddElement);
    }
    
    // Copy back to original array
    for (size_t j = 0; j < mainChain.size(); ++j) {
        arr[left + j] = mainChain[j];
    }
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;
    mergeInsertDeque(arr, 0, arr.size() - 1);
}

void PmergeMe::displayResults(double vectorTime, double dequeTime, int size) {
    std::cout << "Time to process a range of " << size << " elements with std::vector : " 
              << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::deque : " 
              << dequeTime << " us" << std::endl;
}

void PmergeMe::sortAndTime() {
    printSequence(_vectorContainer, "Before: ");
    
    // Time vector sorting
    double startTime = getTime();
    std::vector<int> vectorCopy = _vectorContainer;
    fordJohnsonSortVector(vectorCopy);
    double endTime = getTime();
    double vectorTime = endTime - startTime;
    
    // Time deque sorting
    startTime = getTime();
    std::deque<int> dequeCopy = _dequeContainer;
    fordJohnsonSortDeque(dequeCopy);
    endTime = getTime();
    double dequeTime = endTime - startTime;
    
    printSequence(vectorCopy, "After: ");
    displayResults(vectorTime, dequeTime, _vectorContainer.size());
}