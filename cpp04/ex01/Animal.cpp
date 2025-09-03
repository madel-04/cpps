#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "[Animal] default ctor (type='" << type << "')\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "[Animal] copy ctor (type='" << type << "')\n";
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal] copy assignment\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] dtor\n";
}

void Animal::makeSound() const {
    std::cout << "[Animal] (generic animal sound)\n";
}

std::string Animal::getType() const {
    return type;
}