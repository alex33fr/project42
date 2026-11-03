#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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
    std::cout << std::endl << "Test 4: ScavTrap actions and copy" << std::endl;
    {
        ScavTrap serena("Serena");
        serena.attack("Bob");
        serena.takeDamage(30);
        serena.beRepaired(10);
        serena.guardGate();

        ScavTrap copy(serena);
        ScavTrap assigned;
        assigned = serena;
        assigned.attack("Bob");
    }

    std::cout << std::endl << "Test 5: ScavTrap out of energy" << std::endl;
    {
        ScavTrap serena("Serena");
        for (int i = 0; i < 51; i++)
            serena.attack("Bob");
        serena.beRepaired(1);
    }

    std::cout << std::endl << "Test 6: ScavTrap dead" << std::endl;
    {
        ScavTrap serena("Serena");
        serena.takeDamage(100);
        serena.attack("Bob");
        serena.beRepaired(5);
    }
    return (0);
}
