#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


static void separator(const std::string& title) {
std::cout << "\n==================== " << title << " ====================\n";
}


int main()
{
    separator("Basic polymorphism with Brain");
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;


    separator("Array of Animals (half dogs, half cats)");
    const size_t N = 6;
    Animal* zoo[N];
    for (size_t k = 0; k < N; ++k) {
    if (k < N/2)
    zoo[k] = new Dog();
    else
    zoo[k] = new Cat();
    }
    for (size_t k = 0; k < N; ++k) {
    zoo[k]->makeSound();
    }
    for (size_t k = 0; k < N; ++k) {
    delete zoo[k];
    }


    separator("Deep copy test (Dog)");
    Dog dog1;
    dog1.setIdea(0, "Chase the ball");
    Dog dog2 = dog1; // copy ctor (deep)
    std::cout << "dog1 idea[0] = " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea[0] = " << dog2.getIdea(0) << std::endl;
    dog2.setIdea(0, "Eat bone");
    std::cout << "After modifying dog2:\n";
    std::cout << "dog1 idea[0] = " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea[0] = " << dog2.getIdea(0) << std::endl;


    separator("Deep copy test (Cat)");
    Cat cat1;
    cat1.setIdea(0, "Sleep on couch");
    Cat cat2;
    cat2 = cat1; // copy assignment (deep)
    std::cout << "cat1 idea[0] = " << cat1.getIdea(0) << std::endl;
    std::cout << "cat2 idea[0] = " << cat2.getIdea(0) << std::endl;
    cat2.setIdea(0, "Scratch furniture");
    std::cout << "After modifying cat2:\n";
    std::cout << "cat1 idea[0] = " << cat1.getIdea(0) << std::endl;
    std::cout << "cat2 idea[0] = " << cat2.getIdea(0) << std::endl;


    separator("Done");
    return 0;
}
