#include "Character.hpp"

Character::Character() : name("")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(std::string const & name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(const Character& other) : name(other.name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
	// TODO: deep copy other.inventory
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		// TODO: delete current materias, then deep copy (and copy name)
	}
	return *this;
}

Character::~Character()
{
	// TODO: delete materias (and floor)
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	// TODO: first empty slot 0..3, else nothing
	(void)m;
}

void Character::unequip(int idx)
{
	// TODO: do NOT delete, keep the address to avoid a leak
	(void)idx;
}

void Character::use(int idx, ICharacter& target)
{
	// TODO: check idx and slot, then inventory[idx]->use(target)
	(void)idx;
	(void)target;
}
