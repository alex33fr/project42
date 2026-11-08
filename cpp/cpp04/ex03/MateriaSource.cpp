#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// TODO
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	// TODO: deep copy
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	// TODO
}

MateriaSource::~MateriaSource()
{
	// TODO
}

void MateriaSource::learnMateria(AMateria* m)
{
	// TODO: max 4. who owns m? full -> leak?
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	// TODO: unknown type -> 0
}
