#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "[Cat] default ctor (type='" << type << "')\n";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "[Cat] copy ctor\n";
    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] copy assignment\n";
    if (this != &other) {
        Animal::operator=(other);
        *this->brain = *other.brain;
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "[Cat] dtor\n";
}

void Cat::makeSound() const {
    std::cout << "[Cat] Meow!\n";
}

void Cat::setIdea(size_t idx, const std::string& idea) {
    brain->setIdea(idx, idea);
}

std::string Cat::getIdea(size_t idx) const {
    return brain->getIdea(idx);
}
