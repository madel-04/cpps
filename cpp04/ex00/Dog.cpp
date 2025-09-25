#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "[Dog] default ctor (type='" << type << "')\n";
}
//Fijamos Dog como tipo por defecto

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "[Dog] copy ctor\n";
    this->type = other.type; // explicit for clarity
}
//Llamamos a Animal(other) en la lista de inicialización para construir la parte base
//y nos aseguramos que el tipo refleje other

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] copy assignment\n";
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] dtor\n";
}

void Dog::makeSound() const {
    std::cout << "[Dog] Woof!\n";
}

//Makesound está sobreescrito y, por ser virtual, se asegura que se llame al de Dog en lugar del de Animal.
