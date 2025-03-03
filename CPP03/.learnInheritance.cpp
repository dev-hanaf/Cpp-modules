#include <iostream>

using namespace std;

//inheritance is-a relationship between two classes. is about to inherit features and propreties to a derived class from a base class


//inheritance types:
//single
//multilevel
//multiple
//heirarchical
//hybrid
//multipath


//modes of inhertince
// 1.public ==> ( visible to evryone )
// 2.protected ( visible to current class and derived class)
// 3.private ( visible to current class only )



// ---------------------------------------------------------------------------------
// Base class   |   Derived Class       Derived Class           Derived Class      |
// ---------------------------------------------------------------------------------
//              |   public mode         private mode            Protected mode     |
// ---------------------------------------------------------------------------------
// private      | Not inherited        Not inherited             Not inherited     |1
// Protected    | Ptotected             Private                   Ptotected        |2
// Public       | Public                Private                   Ptotected        |3
// ---------------------------------------------------------------------------------

/* class Base
{
    private: //applying 1 row we see that all private proprties are not inherited
        int x = 5;
};
class Derived : public  Base
{
    public:
        void foo(){x = 300;cout << x << endl;}
}; */

class Base
{
    protected:
        int x = 5;
};
class Derived : private  Base
{
    public:
        void foo(){x = 300;cout << x << endl;}
};

class Derived1: public Derived  
{
    public:
        void foo(){x = 300;cout << x << endl;}
};

int main(void)
{
    Derived d1;

    // d1.x = 40;
    d1.foo();
    return 0;
}