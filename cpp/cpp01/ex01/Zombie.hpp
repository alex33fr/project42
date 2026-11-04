#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
    public:
        void announce( void ) const;
        Zombie();
        ~Zombie();
        void setName( std::string name );
    private:
        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif