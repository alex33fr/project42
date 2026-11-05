#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl << "1. Actions and copy" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    {
        ClapTrap alex("Alex");
        alex.attack("Bob");
        alex.takeDamage(3);
        alex.beRepaired(2);

        ClapTrap copy(alex);
        ClapTrap assigned;
        assigned = alex;
    }

    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl << "2. Out of energy" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    {
        ClapTrap alex("Alex");
        for (int i = 0; i < 11; i++)
            alex.attack("Bob");
        std::cout << "***Try to repair***" << std::endl;
        alex.beRepaired(1);
    }

    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl << "3. Dead robot" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    {
        ClapTrap alex("Alex");
        alex.takeDamage(100);
        std::cout << "***Try to attack***" << std::endl;
        alex.attack("Bob");
        std::cout << "***Try to repair***" << std::endl;
        alex.beRepaired(5);
    }
    return (0);
}
