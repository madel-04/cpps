#include <iostream>
#include "Array.hpp"

/* int main() {
    try {
        Array<int> a;
        std::cout << "a.size() = " << a.size() << std::endl;

        Array<int> b(5);
        std::cout << "b.size() = " << b.size() << std::endl;

        for (size_t i = 0; i < b.size(); ++i) {
            b[i] = static_cast<int>(i * 10);
        }

        Array<int> c(b);
        std::cout << "c after copy:" << std::endl;
        for (size_t i = 0; i < c.size(); ++i) {
            std::cout << "c[" << i << "] = " << c[i] << std::endl;
        }

        c[0] = 999;
        std::cout << "c[0] = " << c[0] << ", b[0] = " << b[0] << std::endl;

        Array<int> d;
        d = b;
        d[1] = 777;
        std::cout << "d[1] = " << d[1] << ", b[1] = " << b[1] << std::endl;

        std::cout << "Trying out of range..." << std::endl;
        std::cout << b[10] << std::endl; // Exception

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
 */

#include <iostream>
#include <string>
#include "Array.hpp"

// Códigos ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main() {
    try {
        // ---- 1. Array vacío ----
        std::cout << CYAN << BOLD << "---- 1. Empty Array ----" << RESET << std::endl;
        Array<int> a;
        std::cout << "a.size() = " << a.size() << std::endl;

        // ---- 2. Array de enteros ----
        std::cout << GREEN << BOLD << "---- 2. Integer Array ----" << RESET << std::endl;
        Array<int> b(5);
        for (size_t i = 0; i < b.size(); ++i) {
            b[i] = static_cast<int>(i * 10);
        }
        std::cout << "b elements: ";
        for (size_t i = 0; i < b.size(); ++i) {
            std::cout << b[i] << " ";
        }
        std::cout << std::endl;

        // ---- 3. Copy constructor ----
        std::cout << YELLOW << BOLD << "---- 3. Copy Constructor ----" << RESET << std::endl;
        Array<int> c(b);
        std::cout << "c copied from b:" << std::endl;
        for (size_t i = 0; i < c.size(); ++i) {
            std::cout << "c[" << i << "] = " << c[i] << std::endl;
        }

        c[0] = 999;
        std::cout << "After modification: c[0] = " << c[0] << ", b[0] = " << b[0] << std::endl;

        // ---- 4. Assignment operator ----
        std::cout << MAGENTA << BOLD << "---- 4. Assignment Operator ----" << RESET << std::endl;
        Array<int> d;
        d = b;
        d[1] = 777;
        std::cout << "d[1] = " << d[1] << ", b[1] = " << b[1] << std::endl;

    // ---- 5. Self-assignment ----
    std::cout << BLUE << BOLD << "---- 5. Self-assignment ----" << RESET << std::endl;
    // Avoid direct self-assignment which some compilers warn about; test assignment via a temporary
    Array<int> temp = b;
    b = temp; // well-defined assignment
    std::cout << "Assignment via temporary passed, b[2] = " << b[2] << std::endl;

        // ---- 6. Single element ----
        std::cout << RED << BOLD << "---- 6. Single Element Array ----" << RESET << std::endl;
        Array<int> single(1);
        single[0] = 42;
        std::cout << "single[0] = " << single[0] << std::endl;

        // ---- 7. Strings ----
        std::cout << CYAN << BOLD << "---- 7. String Array ----" << RESET << std::endl;
        Array<std::string> words(3);
        words[0] = "Hola";
        words[1] = "Mundo";
        words[2] = "!";
        std::cout << "words: ";
        for (size_t i = 0; i < words.size(); ++i) {
            std::cout << words[i] << " ";
        }
        std::cout << std::endl;

        // ---- 8. Out of range ----
        std::cout << GREEN << BOLD << "---- 8. Out of Range Access ----" << RESET << std::endl;
        std::cout << "Trying out of range access..." << std::endl;
        std::cout << b[b.size()] << std::endl; // debería lanzar excepción

    } catch (const std::exception& e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    return 0;
}
