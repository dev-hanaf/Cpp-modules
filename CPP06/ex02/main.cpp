#include "Base.hpp"

int main()
{
    Base *dv = generate();
    identify(dv);
    identify(*dv);
}