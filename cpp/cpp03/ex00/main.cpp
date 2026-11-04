#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "Test 1: actions and copy" << std::endl;
    {
        ClapTrap alex("Alex");
        alex.attack("Bob");
        alex.takeDamage(3);
        alex.beRepaired(2);

        ClapTrap copy(alex);
        ClapTrap assigned;
        assigned = alex;
    }

    std::cout << std::endl << "Test 2: out of energy" << std::endl;
    {
        ClapTrap alex("Alex");
        for (int i = 0; i < 11; i++)
            alex.attack("Bob");
        alex.beRepaired(1);
    }

    std::cout << std::endl << "Test 3: dead robot" << std::endl;
    {
        ClapTrap alex("Alex");
        alex.takeDamage(100);
        alex.attack("Bob");
        alex.beRepaired(5);
    }
    return (0);
}
