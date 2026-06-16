#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* learned_[4];

	void clearLearned();
	void cloneFrom(MateriaSource const & other);

public:
	MateriaSource();
	MateriaSource(MateriaSource const & other);
	virtual ~MateriaSource();
	MateriaSource & operator=(MateriaSource const & other);

	virtual void learnMateria(AMateria* materia);
	virtual AMateria* createMateria(std::string const & type);
};

#endif