#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "[Cat] default ctor (type='" << type << "')\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "[Cat] copy ctor\n";
    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] copy assignment\n";
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] dtor\n";
}

void Cat::makeSound() const {
    std::cout << "[Cat] Meow!\n";
}