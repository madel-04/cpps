#include <iostream>
#include <sstream>
#include <string>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

namespace
{
void printCaseResult(std::string const & name, bool ok)
{
	std::cout << "[TEST] " << name << ": " << (ok ? "PASS" : "FAIL") << std::endl;
}

bool expectOutput(std::string const & expected, std::string const & actual)
{
	return expected == actual;
}

bool runSilentTests()
{
	bool ok = true;

	MateriaSource source;
	source.learnMateria(new Ice());
	source.learnMateria(new Cure());
	source.learnMateria(new Ice());
	source.learnMateria(new Cure());
	source.learnMateria(new Ice());
	AMateria* ice = source.createMateria("ice");
	if (ice == 0)
	{
		printCaseResult("createMateria('ice') returns a materia", false);
		return false;
	}
	delete ice;
	AMateria* unknown = source.createMateria("unknown");
	if (unknown != 0)
	{
		delete unknown;
		printCaseResult("createMateria('unknown') returns 0", false);
		return false;
	}
	printCaseResult("createMateria('unknown') returns 0", true);
	AMateria* knownAfterOverflow = source.createMateria("cure");
	bool sourceCapacity = (knownAfterOverflow != 0);
	if (knownAfterOverflow != 0)
		delete knownAfterOverflow;
	printCaseResult("source still creates learned materias after overflow", sourceCapacity);
	ok = ok && sourceCapacity;

	Character alice("alice");
	Character bob("bob");
	Character charlie("charlie");
	Character full("full");
	Character empty("empty");

	alice.equip(source.createMateria("ice"));
	alice.equip(source.createMateria("cure"));
	alice.equip(source.createMateria("ice"));
	alice.equip(source.createMateria("cure"));
	alice.equip(source.createMateria("ice"));
	Character copy(alice);
	Character assigned("assigned");
	assigned = alice;

	alice.unequip(0);
	alice.unequip(1);
	alice.unequip(-1);
	alice.unequip(99);
	copy.unequip(2);
	copy.unequip(2);
	assigned.unequip(3);
	assigned.unequip(3);

	std::ostringstream capture;
	std::streambuf* oldBuffer = std::cout.rdbuf(capture.rdbuf());
	copy.use(0, bob);
	copy.use(1, bob);
	copy.use(2, bob);
	copy.use(3, bob);
	copy.use(-1, bob);
	copy.use(99, bob);
	assigned.use(0, bob);
	assigned.use(1, bob);
	assigned.use(2, bob);
	assigned.use(3, bob);
	empty.use(0, bob);
	empty.use(1, bob);
	std::cout.rdbuf(oldBuffer);

	const std::string expectedCopyAndAssign =
		"* shoots an ice bolt at bob *\n"
		"* heals bob's wounds *\n"
		"* heals bob's wounds *\n"
		"* shoots an ice bolt at bob *\n"
		"* heals bob's wounds *\n"
		"* shoots an ice bolt at bob *\n";
	bool deepCopyAndSlotBounds = expectOutput(expectedCopyAndAssign, capture.str());
	printCaseResult("deep copy keeps materias after unequip", deepCopyAndSlotBounds);
	ok = ok && deepCopyAndSlotBounds;

	std::ostringstream captureInventory;
	oldBuffer = std::cout.rdbuf(captureInventory.rdbuf());
	full.equip(source.createMateria("ice"));
	full.equip(source.createMateria("cure"));
	full.equip(source.createMateria("ice"));
	full.equip(source.createMateria("cure"));
	AMateria* dropped = source.createMateria("ice");
	full.equip(dropped);
	full.use(0, charlie);
	full.use(1, charlie);
	full.use(2, charlie);
	full.use(3, charlie);
	full.use(4, charlie);
	std::cout.rdbuf(oldBuffer);

	const std::string expectedInventory =
		"* shoots an ice bolt at charlie *\n"
		"* heals charlie's wounds *\n"
		"* shoots an ice bolt at charlie *\n"
		"* heals charlie's wounds *\n";
	bool inventoryLimit = expectOutput(expectedInventory, captureInventory.str());
	printCaseResult("equip ignores slot 5 and invalid use indexes", inventoryLimit);
	ok = ok && inventoryLimit;

	std::ostringstream captureInvalid;
	oldBuffer = std::cout.rdbuf(captureInvalid.rdbuf());
	empty.use(0, bob);
	empty.use(-1, bob);
	empty.use(7, bob);
	empty.unequip(0);
	empty.unequip(-1);
	empty.unequip(7);
	std::cout.rdbuf(oldBuffer);
	bool invalidOperationsSilent = expectOutput(std::string(), captureInvalid.str());
	printCaseResult("invalid use/unequip stays silent", invalidOperationsSilent);
	ok = ok && invalidOperationsSilent;

	printCaseResult("overall harness", ok);

	return ok;
}
}

int main()
{
	if (!runSilentTests())
	{
		std::cerr << "Self-test failed" << std::endl;
		return 1;
	}

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}