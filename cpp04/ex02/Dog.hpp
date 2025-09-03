#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* brain;

    public:
    // Orthodox Canonical Form
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    // Polymorphic behavior
    virtual void makeSound() const;

    //Brain access
    void setIdea(size_t idx, const std::string& idea);
    std::string getIdea(size_t idx) const;

};

#endif // DOG_HPP

/*
Aseguramos que Dog sea de herencia pública, tipo Animal.
*/