#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl << "1. ClapTrap actions" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    {
        ClapTrap alex("Alex");
        alex.attack("Bob");
        alex.takeDamage(3);
        alex.beRepaired(2);
    }

    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl << "2. ScavTrap actions" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    {
        ScavTrap serena("Serena");
        serena.attack("Bob");
        serena.takeDamage(30);
        serena.beRepaired(10);
        serena.guardGate();
    }

    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl << "3. FragTrap actions and copy" << std::endl;
    std::cout << "---------------------------------" << std::endl;
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

    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl << "4. FragTrap out of energy" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    {
        FragTrap frag("Frag");
        for (int i = 0; i < 105; i++)
            frag.attack("Bob");
        std::cout << "***Try to repair***" << std::endl;
        frag.beRepaired(1);
    }

    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl << "5. FragTrap dead" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    {
        FragTrap frag("Frag");
        frag.takeDamage(100);
        std::cout << "***Try to attack***" << std::endl;
        frag.attack("Bob");
        std::cout << "***Try to repair***" << std::endl;
        frag.beRepaired(5);
        std::cout << "***Try to high five***" << std::endl;
        frag.highFivesGuys();
    }
    return (0);
}
