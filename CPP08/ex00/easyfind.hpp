#pragma once

#include <iostream>
#include <algorithm>

template<typename Container>
typename Container::iterator easyfind(Container &container, int toFind)
{
    return std::find(container.begin(), container.end(), toFind);
}