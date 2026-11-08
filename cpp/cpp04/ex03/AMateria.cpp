#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type)
{
	// TODO
}

AMateria::AMateria(const AMateria& other)
{
	// TODO
}

AMateria& AMateria::operator=(const AMateria& other)
{
	// TODO: read the subject about the type
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	// TODO
}

void AMateria::use(ICharacter& target)
{
	// TODO: what should a generic materia do?
}
