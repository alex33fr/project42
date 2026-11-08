#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int i, std::string const & idea)
{
	if(i < 0 || i >= 100)
	{
		std::cout << "Index out of range" << std::endl;
		return;
	}
	ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	if(i < 0 || i >= 100)
	{
		std::cout << "Index out of range" << std::endl;
		return "";
	}
	return (ideas[i]);
}
