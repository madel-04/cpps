#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "[Dog] default ctor (type='" << type << "')\n";
}
//Fijamos Dog como tipo por defecto

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "[Dog] copy ctor\n";
    this->type = other.type; // explicit for clarity
}
//Llamamos a Animal(other) en la lista de inicialización para construir la parte base
//y nos aseguramos que el tipo refleje other

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] copy assignment\n";
    if (this != &other) {
        Animal::operator=(other);
        *this->brain = *other.brain;
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "[Dog] dtor\n";
}

void Dog::makeSound() const {
    std::cout << "[Dog] Woof!\n";
}

void Dog::setIdea(size_t idx, const std::string& idea) {
    brain->setIdea(idx, idea);
}

std::string Dog::getIdea(size_t idx) const {
    return brain->getIdea(idx);
}

//Makesound está sobreescrito y, por ser virtual, se asegura que se llame al de Dog en lugar del de Animal.
