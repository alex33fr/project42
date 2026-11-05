#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure& other) : AMateria(other)
{
}

Cure& Cure::operator=(const Cure& other)
{
	AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	// TODO: return new Cure(*this);
	return 0;
}

void Cure::use(ICharacter& target)
{
	// TODO: print the message using target.getName()
	(void)target;
}
