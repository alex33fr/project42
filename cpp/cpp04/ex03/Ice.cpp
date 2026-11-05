#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice& other) : AMateria(other)
{
}

Ice& Ice::operator=(const Ice& other)
{
	AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
	// TODO: return new Ice(*this);
	return 0;
}

void Ice::use(ICharacter& target)
{
	// TODO: print the message using target.getName()
	(void)target;
}
