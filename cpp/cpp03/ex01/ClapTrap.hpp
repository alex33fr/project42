#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
    public:
        ClapTrap( void );
        ClapTrap( std::string name );
        ClapTrap( const ClapTrap &other );
        ~ClapTrap( void );
        void attack( const std::string &target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );
        ClapTrap &operator=(const ClapTrap &other);

    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
};

#endif
