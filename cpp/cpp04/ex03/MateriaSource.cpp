#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
		templates[i] = 0;
	// TODO: deep copy other.templates
	(void)other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		// TODO: delete current templates, then deep copy
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	// TODO: delete templates
}

void MateriaSource::learnMateria(AMateria* m)
{
	// TODO: store the Materia in the first free slot (max 4)
	(void)m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	// TODO: return a clone of the learned materia of this type, or 0
	(void)type;
	return 0;
}
