#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string name_;
	AMateria* inventory_[4];
	std::vector<AMateria*> floor_;

	void clearInventory();
	void clearFloor();
	void cloneFrom(Character const & other);

public:
	Character();
	Character(std::string const & name);
	Character(Character const & other);
	virtual ~Character();
	Character & operator=(Character const & other);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif