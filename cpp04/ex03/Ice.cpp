#include "Ice.hpp"

#include <iostream>

#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const & other) : AMateria(other)
{
}

Ice::~Ice()
{
}

Ice & Ice::operator=(Ice const & other)
{
	(void)other;
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}