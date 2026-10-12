#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap( void )
: _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default called constructor" << std::endl;
}

ClapTrap::ClapTrap( std::string name )
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << _name << " called constructor" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other )
{
    ClapTrap::operator=( other );
    std::cout << other._name << " called copy constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack( const std::string &target )
{
    if( _hitPoints == 0 || _energyPoints == 0)
    {
        if (_energyPoints == 0)
        {
            std::cout << _name << " empty energy points" << std::endl;
            return ;
        }
        std::cout << _name << " empty hit points" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
    
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if(_hitPoints == 0)
    {
        std::cout << "Robot is dead " << _name << std::endl;
        return ;
    }
    if(amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! (" << _hitPoints << " hit points left)" << std::endl;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &other )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &other)
        return (*this);
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return (*this);
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if( _hitPoints == 0 || _energyPoints == 0)
    {
        if (_energyPoints == 0)
        {
            std::cout << _name << " empty energy points" << std::endl;
            return ;
        }
        std::cout << _name << " robot is dead" << std::endl;
        return ;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name
    << " repairs itself for " << amount
    << " hit points! (" << _hitPoints
    << " hit points)" << std::endl;
}