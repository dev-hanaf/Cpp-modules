#pragma once

#include <exception>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

template<typename T> 
class Array
{
    private:
        T *array;
        unsigned int _size;
    public:
        Array() : _size(0)
        {
            array = NULL;
        }

        Array(unsigned int n) : _size(n)
        {
            array = new T[_size];
        }

        Array(const Array &obj)
        {
            _size = obj._size;
            array = new T[_size];
            for (unsigned int  i=0 ; i < _size; i++)
                this->array[i] = obj.array[i];
        }

        Array &operator=(const Array &obj)
        {
            if (this != &obj)
            {
                delete [] array;
                _size = obj._size;
                array = new T[_size];
                for (unsigned int  i=0 ; i < _size; i++)
                    this->array[i] = obj.array[i];
            }
            return *this;
        }

        T &operator[](unsigned int n)
        {
            if  (n >= _size)
                throw std::out_of_range("out of bounds");
            return array[n];
        }


        const T &operator[](unsigned int n) const
        {
            if  (n >= _size)
                throw std::out_of_range("out of bounds");
            return array[n];
        }

        unsigned int size() const
        {
            return _size;
        }
};
