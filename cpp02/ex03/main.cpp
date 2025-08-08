#include <iostream>
#include "Point.hpp"

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(2, 2);
    Point outside(20, 20);
    Point edge(0, 0);

    std::cout << "Inside (2,2): " << bsp(a, b, c, inside) << std::endl; // 1
    std::cout << "Outside (20,20): " << bsp(a, b, c, outside) << std::endl; // 0
    std::cout << "Edge (0,0): " << bsp(a, b, c, edge) << std::endl; // 0

    return 0;
}
