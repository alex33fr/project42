#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] != NULL)
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i] != NULL)
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Cannot learn NULL materia" << std::endl;
		return ;
	}
	std::cout << "MateriaSource learning materia of type " << m->getType() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << "Materia learned at index " << i << std::endl;
			return ;
		}
	}
	std::cout << "Inventory full, cannot learn materia of type " << m->getType() << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL && inventory[i]->getType() == type)
		{
			std::cout << "Creating materia of type " << type << std::endl;
			return (inventory[i]->clone());
		}
	}
	std::cout << "Materia of type " << type << " not found" << std::endl;
	return (NULL);
}
