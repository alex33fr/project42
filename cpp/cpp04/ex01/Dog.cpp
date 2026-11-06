#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	// TODO: create the brain (new Brain)
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	// TODO: deep copy: create a NEW Brain copied from *other.brain
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		// TODO: delete the old brain, then deep copy other's brain
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	// TODO: delete the brain
}

void Dog::makeSound() const
{
	// TODO: print the dog sound
}
