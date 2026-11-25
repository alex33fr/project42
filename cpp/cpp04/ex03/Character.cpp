#include "Character.hpp"

Character::Character() : name("Default Character")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string const & name) : name(name)
{
	std::cout << "Character parameterized constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other) : name(other.name)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] != NULL)
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i] != NULL)
			{
				this->inventory[i] = other.inventory[i]->clone();
			}
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

std::string const & Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	if(m == NULL)
	{
		std::cout << "Cannot equip NULL materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << "Equipped materia of type " << m->getType() << " at index " << i << std::endl;
			return ;
		}
	}
	std::cout << "Inventory full, cannot equip materia of type " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
	std::cout << "Character unequip called" << std::endl;
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (inventory[idx] == NULL)
	{
		std::cout << "No materia to unequip at index " << idx << std::endl;
		return ;
	}
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	std::cout << "Character use called" << std::endl;
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (inventory[idx] == NULL)
	{
		std::cout << "No materia to use at index " << idx << std::endl;
		return ;
	}
	inventory[idx]->use(target);
}

