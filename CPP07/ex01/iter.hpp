#pragma once

#include <cstddef>
#include <iostream>


template<typename T, typename Tf>
void iter(T *array, int lenght, Tf (*func)(T &))
{
    if (!array || !func)
        return;
    for(int i=0; i < lenght; i++)
        func(array[i]);
}

template<typename T, typename Tf>
void iter(T *array, int lenght, Tf (*func)(const T &))
{
    if (!array || !func)
        return;
    for(int i=0; i < lenght; i++)
        func(array[i]);
}