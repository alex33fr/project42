#include "Harl.hpp"
#include <string>
#include <iostream>

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (1);
    }
    Harl harl;
    harl.complain(av[1]);
    return (0);
}
