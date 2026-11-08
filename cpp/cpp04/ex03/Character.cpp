#include "Character.hpp"

Character::Character()
{
	// TODO: empty inventory
}

Character::Character(std::string const & name)
{
	// TODO
}

Character::Character(const Character& other)
{
	// TODO: deep copy
}

Character& Character::operator=(const Character& other)
{
	// TODO: delete the old materias FIRST, then deep copy
}

Character::~Character()
{
	// TODO
}

std::string const & Character::getName() const
{
	// TODO
}

void Character::equip(AMateria* m)
{
	// TODO: first empty slot (0 -> 3), full -> nothing
}

void Character::unequip(int idx)
{
	// TODO: no delete! who frees it then?
}

void Character::use(int idx, ICharacter& target)
{
	// TODO
}
