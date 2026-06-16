#include "MateriaSource.hpp"

#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		learned_[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
	for (int i = 0; i < 4; ++i)
		learned_[i] = 0;
	cloneFrom(other);
}

MateriaSource::~MateriaSource()
{
	clearLearned();
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
	if (this != &other)
	{
		clearLearned();
		cloneFrom(other);
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == 0)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (learned_[i] == 0)
		{
			learned_[i] = materia->clone();
			delete materia;
			return;
		}
	}
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (learned_[i] != 0 && learned_[i]->getType() == type)
			return learned_[i]->clone();
	}
	return 0;
}

void MateriaSource::clearLearned()
{
	for (int i = 0; i < 4; ++i)
	{
		delete learned_[i];
		learned_[i] = 0;
	}
}

void MateriaSource::cloneFrom(MateriaSource const & other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.learned_[i] != 0)
			learned_[i] = other.learned_[i]->clone();
	}
}