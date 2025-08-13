#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    // Orthodox Canonical Form
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    // Polymorphic behavior
    virtual void makeSound() const;
};

#endif // DOG_HPP

/*
Aseguramos que Dog sea de herencia pública, tipo Animal.
*/