#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "Test Actions and copy" << std::endl;
    {
        ClapTrap alex("Alex");
        alex.attack("Bob");
        alex.takeDamage(3);
        alex.beRepaired(2);

        ClapTrap copy(alex);
        ClapTrap assigned;
        assigned = alex;
    }

    std::cout << std::endl << "Test Out of energy" << std::endl;
    {
        ClapTrap alex("Alex");
        for (int i = 0; i < 5; i++)
            alex.attack("Bob");
        alex.beRepaired(1);
    }

    std::cout << std::endl << "Test Dead robot" << std::endl;
    {
        ClapTrap alex("Alex");
        alex.takeDamage(100);
        alex.attack("Bob");
        alex.beRepaired(5);
    }
    return (0);
}
