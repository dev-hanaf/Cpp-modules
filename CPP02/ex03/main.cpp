#include <iostream>
#include "Point.hpp"

int main()
{
    // Define the vertices of the triangle
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    // Test points
    Point inside(2, 2);    // Inside the triangle
    Point outside(10, 10); // Outside the triangle
    Point edge(5, 0);      // On the edge of the triangle
    Point vertex(0, 0);    // On a vertex of the triangle

    // Test the bsp function
    std::cout << "Inside: " << (bsp(a, b, c, inside) ? "Yes" : "No") << std::endl;
    std::cout << "Outside: " << (bsp(a, b, c, outside) ? "Yes" : "No") << std::endl;
    std::cout << "Edge: " << (bsp(a, b, c, edge) ? "Yes" : "No") << std::endl;
    std::cout << "Vertex: " << (bsp(a, b, c, vertex) ? "Yes" : "No") << std::endl;

    return 0;
}