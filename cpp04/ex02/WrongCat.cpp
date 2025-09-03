#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "[WrongCat] default ctor (type='" << type << "')\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "[WrongCat] copy ctor\n";
    this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "[WrongCat] copy assignment\n";
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] dtor\n";
}

void WrongCat::makeSound() const {
    std::cout << "[WrongCat] Meow? (but base is non-virtual)\n";
}