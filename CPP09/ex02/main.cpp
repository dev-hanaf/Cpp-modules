#include "PmergeMe.hpp"
#include <sstream>
#include <string>

int main(int ac, char **av)
{	if (ac <= 1)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return 1;
	}
    PmergeMe pmergeMe;
    if (!pmergeMe.parseInput(ac, av))
    {
        return 1;
    }
    pmergeMe.sortAndTime();

    return 0;
}