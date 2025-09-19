#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "[WrongAnimal] default ctor (type='" << type << "')\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "[WrongAnimal] copy ctor\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "[WrongAnimal] copy assignment\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] dtor\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "[WrongAnimal] (generic wrong animal sound)\n";
}

std::string WrongAnimal::getType() const {
    return type;
}
