#include "Character.hpp"

#include "AMateria.hpp"

Character::Character() : name_(), floor_()
{
	for (int i = 0; i < 4; ++i)
		inventory_[i] = 0;
}

Character::Character(std::string const & name) : name_(name), floor_()
{
	for (int i = 0; i < 4; ++i)
		inventory_[i] = 0;
}

Character::Character(Character const & other) : name_(other.name_), floor_()
{
	for (int i = 0; i < 4; ++i)
		inventory_[i] = 0;
	cloneFrom(other);
}

Character::~Character()
{
	clearInventory();
	clearFloor();
}

Character & Character::operator=(Character const & other)
{
	if (this != &other)
	{
		clearInventory();
		clearFloor();
		name_ = other.name_;
		cloneFrom(other);
	}
	return *this;
}

std::string const & Character::getName() const
{
	return name_;
}

void Character::equip(AMateria* m)
{
	if (m == 0)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (inventory_[i] == 0)
		{
			inventory_[i] = m;
			return;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || inventory_[idx] == 0)
		return;
	floor_.push_back(inventory_[idx]);
	inventory_[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || inventory_[idx] == 0)
		return;
	inventory_[idx]->use(target);
}

void Character::clearInventory()
{
	for (int i = 0; i < 4; ++i)
	{
		delete inventory_[i];
		inventory_[i] = 0;
	}
}

void Character::clearFloor()
{
	for (std::vector<AMateria*>::iterator it = floor_.begin(); it != floor_.end(); ++it)
		delete *it;
	floor_.clear();
}

void Character::cloneFrom(Character const & other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory_[i] != 0)
			inventory_[i] = other.inventory_[i]->clone();
	}
	for (std::vector<AMateria*>::const_iterator it = other.floor_.begin(); it != other.floor_.end(); ++it)
	{
		if (*it != 0)
			floor_.push_back((*it)->clone());
	}
}