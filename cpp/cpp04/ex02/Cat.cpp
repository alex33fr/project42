#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	// TODO: create the brain (new Brain)
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	// TODO: deep copy: create a NEW Brain copied from *other.brain
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		// TODO: delete the old brain, then deep copy other's brain
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	// TODO: delete the brain
}

void Cat::makeSound() const
{
	// TODO: print the cat sound
}
