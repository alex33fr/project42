#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	// TODO: type = "Dog"; brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	// TODO: deep copy brain (brain = new Brain(*other.brain))
	// TODO: copy members from other
	(void)other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		// TODO: copy members from other
		(void)other;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	// TODO: delete brain;
}

void Dog::makeSound() const
{
	// TODO
}
