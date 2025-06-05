#pragma once

#include <iostream>

typedef unsigned long int	uintptr_t;

struct Data
{
    int i;
};

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer&);
        Serializer &operator=(const Serializer&);
        ~Serializer();
    public:
        static  uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
