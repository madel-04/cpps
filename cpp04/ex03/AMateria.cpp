#include "AMateria.hpp"

#include "ICharacter.hpp"

AMateria::AMateria() : type_()
{
}

AMateria::AMateria(std::string const & type) : type_(type)
{
}

AMateria::AMateria(AMateria const & other) : type_(other.type_)
{
}

AMateria::~AMateria()
{
}

AMateria & AMateria::operator=(AMateria const & other)
{
	(void)other;
	return *this;
}

std::string const & AMateria::getType() const
{
	return type_;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}