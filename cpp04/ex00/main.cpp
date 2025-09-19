#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void separator(const std::string& title) {
    std::cout << "\n==================== " << title << " ====================\n";
}

int main() {
    separator("Basic polymorphism (correct)");
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound(); // cat sound
    j->makeSound(); // dog sound
    meta->makeSound(); // generic animal sound

    delete i;
    delete j;
    delete meta;

    separator("Wrong polymorphism (non-virtual)");
    WrongAnimal wrongBase;
    WrongCat wrongDerived;

    const WrongAnimal* p = &wrongDerived; // static type = WrongAnimal
    std::cout << p->getType() << std::endl; // prints "WrongCat"
    p->makeSound(); // calls WrongAnimal::makeSound (WRONG behavior)

/*
uando usas un puntero de tipo WrongAnimal que apunta a un objeto
WrongCat y llamas a makeSound(), se ejecuta el método de la clase
base (WrongAnimal), no el de la derivada (WrongCat).
*/

    wrongDerived.makeSound(); // calls WrongCat::makeSound (direct object)

    separator("OCF: copy and assignment");
    Dog d1;
    Dog d2(d1);      // copy ctor
    Dog d3;          // default ctor
    d3 = d1;         // copy assignment
    d1.makeSound();
    d2.makeSound();
    d3.makeSound();

    separator("Array of base pointers (polymorphic cleanup)");
    const size_t N = 4;
    Animal* zoo[N];
    for (size_t k = 0; k < N; ++k) {
        zoo[k] = (k % 2 == 0) ? static_cast<Animal*>(new Dog())
                              : static_cast<Animal*>(new Cat());
    }
    for (size_t k = 0; k < N; ++k) {
        std::cout << k << ": " << zoo[k]->getType() << " -> ";
        zoo[k]->makeSound();
    }
    for (size_t k = 0; k < N; ++k) {
        delete zoo[k]; // virtual dtor ensures correct derived destructor
    }

    separator("Slicing check (informational)");
    Dog dogOriginal;
    Animal sliced = dogOriginal; // object slicing
    std::cout << "sliced.getType() = " << sliced.getType() << std::endl;
    sliced.makeSound(); // generic Animal sound

    separator("Done");
    return 0;
}
