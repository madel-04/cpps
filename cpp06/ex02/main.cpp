#include "Base.hpp"

int main()
{
    std::srand(std::time(nullptr)); 

    std::cout << "=== Test del sistema de identificación de tipos ===" << std::endl;
    
    // Generar varios objetos aleatorios
    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();
        std::cout << "Objeto " << i + 1 << " - Tipo identificado: ";
        identify(obj);
        delete obj;
    }
    
    std::cout << "\n=== Test con referencias ===" << std::endl;
    
    // Crear objetos específicos para test con referencias
    A a;
    B b;
    C c;
    
    std::cout << "Objeto A: ";
    identify(a);
    
    std::cout << "Objeto B: ";
    identify(b);
    
    std::cout << "Objeto C: ";
    identify(c);
    
    return 0;
}