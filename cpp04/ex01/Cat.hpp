#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* brain;

public:
    // Orthodox Canonical Form
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);

    // Brain access
    void setIdea(size_t idx, const std::string& idea);
    std::string getIdea(size_t idx) const;

    virtual ~Cat();

    // Polymorphic behavior
    virtual void makeSound() const;
};

#endif // CAT_HPP