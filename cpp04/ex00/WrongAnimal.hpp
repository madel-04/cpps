#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal(); // NOT virtual on purpose

    void makeSound() const; // NOT virtual on purpose
    std::string getType() const;
};

#endif // WRONGANIMAL_HPP
