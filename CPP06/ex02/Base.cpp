#include "Base.hpp"
#include <cstdlib>

Base::~Base()
{

}

Base * generate(void)
{
    srand(time(0));
    int random = rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            break;
    }
    return NULL;
}


void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "actual type of the object pointed to by p: A" << std::endl;

    if (dynamic_cast<B *>(p))
        std::cout << "actual type of the object pointed to by p: B" << std::endl;

    if (dynamic_cast<C *>(p))
        std::cout << "actual type of the object pointed to by p: C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "actual type of the object pointed to by p: A" << std::endl;
        return;
    }
    catch (...)
    {}

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "actual type of the object pointed to by p: B" << std::endl;
        return;
    }
    catch (...)
    {}


    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "actual type of the object pointed to by p: C" << std::endl;
        return;
    }
    catch (...)
    {}
}