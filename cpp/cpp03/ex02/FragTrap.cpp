#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructor" << std::endl;
}

FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap destructor" << std::endl;
}

FragTrap &FragTrap::operator=( const FragTrap &other )
{
    std::cout << "FragTrap copy assignment" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

void FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}
