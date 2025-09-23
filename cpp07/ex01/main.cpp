#include "iter.hpp"
#include <iostream>
#include <string>

// función que NO modifica, recibe const T&
template <typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

// función que SÍ modifica, recibe T&
template <typename T>
void doubleElement(T& elem) {
    elem = elem * 2;
}

int main() {
    // ==== TEST CON INT ====
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Int array original: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << "\n";

    iter(intArray, intSize, doubleElement<int>);

    std::cout << "Int array modificado (doble): ";
    iter(intArray, intSize, printElement<int>);
    std::cout << "\n\n";


    // ==== TEST CON STRING ====
    std::string strArray[] = {"hola", "mundo", "iter"};
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array original: ";
    iter(strArray, strSize, printElement<std::string>);
    std::cout << "\n";

    // modificamos las strings (no const)
    iter(strArray, strSize, [](std::string& s) {
        s += "!"; // añade un "!" a cada string
    });

    std::cout << "String array modificado: ";
    iter(strArray, strSize, printElement<std::string>);
    std::cout << "\n\n";


    // ==== TEST CON DOUBLE (usando lambda const y no const) ====
    double dblArray[] = {1.1, 2.2, 3.3};
    size_t dblSize = sizeof(dblArray) / sizeof(dblArray[0]);

    std::cout << "Double array original: ";
    iter(dblArray, dblSize, [](const double& d) {
        std::cout << d << " ";
    });
    std::cout << "\n";

    iter(dblArray, dblSize, [](double& d) {
        d += 0.5; // incrementamos cada valor
    });

    std::cout << "Double array modificado: ";
    iter(dblArray, dblSize, [](const double& d) {
        std::cout << d << " ";
    });
    std::cout << "\n";

    return 0;
}
