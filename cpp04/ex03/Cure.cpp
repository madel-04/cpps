#include "Cure.hpp"

#include <iostream>

#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const & other) : AMateria(other)
{
}

Cure::~Cure()
{
}

Cure & Cure::operator=(Cure const & other)
{
	(void)other;
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}