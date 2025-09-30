#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    // Test con vector
    std::vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i);

    try {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Encontrado en vector: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error en vector: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "Encontrado en vector: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error en vector: " << e.what() << std::endl;
    }

    // Test con list
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    try {
        std::list<int>::iterator it = easyfind(l, 20);
        std::cout << "Encontrado en list: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error en list: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(l, 99);
        std::cout << "Encontrado en list: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error en list: " << e.what() << std::endl;
    }

    return 0;
}
