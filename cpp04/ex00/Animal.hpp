#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal(); //Constructor por defecto
    Animal(const Animal& other); //Constructor de copia
    Animal& operator=(const Animal& other); //Operador de asignación
    virtual ~Animal(); //destructor de asignación

    // Interface
    virtual void makeSound() const; // debe ser virtual para el polimorfismo y const para no modificar el estado del objeto
    std::string getType() const; // leer type sin modificarlo
};

#endif // ANIMAL_HPP

/*
Notas:
- Protected: se utiliza para permitir que sea accesible desde Animal y sus clases derivadas
 pero no desde clases no relacionadas.

El destructor es virtual porque si borras un Dog a través de un puntero de tipo Animal, se asegurará de que se llame al destructor de Dog y luego subir a Animal, evitando así fugas de memoria.
 */
