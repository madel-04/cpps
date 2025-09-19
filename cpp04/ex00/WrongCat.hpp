#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    // Orthodox Canonical Form
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat(); // NOT virtual (still fine: we *inherit* non-virtual)

    void makeSound() const; // this *hides* base but won't be used via base ptr
};

#endif // WRONGCAT_HPP

/*
¿Por qué es útil? Esto muestra que, sin métodos virtuales, el 
comportamiento polimórfico no funciona: el método de la clase base 
se ejecuta aunque el objeto sea de la clase derivada.
*/
