#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "Test 1: ClapTrap" << std::endl;
    {
        ClapTrap alex("Alex");
        alex.attack("Bob");
        alex.takeDamage(3);
        alex.beRepaired(2);
    }

    std::cout << std::endl << "Test 2: ScavTrap" << std::endl;
    {
        ScavTrap serena("Serena");
        serena.attack("Bob");
        serena.takeDamage(30);
        serena.beRepaired(10);
        serena.guardGate();
    }

    std::cout << std::endl << "Test 3: FragTrap actions and copy" << std::endl;
    {
        FragTrap frag("Frag");
        frag.attack("Bob");
        frag.takeDamage(30);
        frag.beRepaired(10);
        frag.highFivesGuys();

        FragTrap copy(frag);
        FragTrap assigned;
        assigned = frag;
        assigned.highFivesGuys();
    }

    std::cout << std::endl << "Test 4: FragTrap out of energy" << std::endl;
    {
        FragTrap frag("Frag");
        for (int i = 0; i < 101; i++)
            frag.attack("Bob");
        frag.beRepaired(1);
    }

    std::cout << std::endl << "Test 5: FragTrap dead" << std::endl;
    {
        FragTrap frag("Frag");
        frag.takeDamage(100);
        frag.attack("Bob");
        frag.beRepaired(5);
        frag.highFivesGuys();
    }
    return (0);
}
