#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main() {
    Point A(0, 0), B(5, 0), C(2.5, 5);
    Point P(2.5, 2);  // Inside
    Point Q(5, 5);    // Outside

    std::cout << "Point P inside: " << (bsp(A, B, C, P) ? "Yes" : "No") << std::endl;
    std::cout << "Point Q inside: " << (bsp(A, B, C, Q) ? "Yes" : "No") << std::endl;

    return 0;
}