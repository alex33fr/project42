#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructor" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap destructor" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &other )
{
    std::cout << "ScavTrap copy assignment" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

void ScavTrap::attack( const std::string &target )
{
    if (_hitPoints == 0 || _energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

void ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode" << std::endl;
}
