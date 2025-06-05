#include "whatever.hpp"
#include <cassert>

int main()
{
    // int x = 10;
    // int y = 200;

    // std::cout << "x = " << x << " y = " << y << std::endl;
    // ::swap(x, y);
    // std::cout << "x = " << x << " y = " << y << std::endl;

    // std::cout << "min(" << x << ", " << y << ") = " << min(x, y) << '\n';
    // // assert(::min(x, y) == y);

    
    // std::cout << "max(" << x << ", " << y << ") = " << max(x, y) << '\n';
    // // assert(::max(x, y) == y);
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}