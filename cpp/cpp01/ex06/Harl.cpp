#include "Harl.hpp"
#include <iostream>
#include <string>

void Harl::debug( void ){std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << "I really do!" << std::endl;}
void Harl::info( void ){std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;}
void Harl::warning( void ){std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I've been coming for years, whereas you started working here just last month." << std::endl;}
void Harl::error( void ){std::cout << "This is unacceptable!" << std::endl << "I want to speak to the manager now." << std::endl;}

void Harl::complain( std::string level)
{
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};
    int j = -1;
    for (int i = 0; i < 4; i++)
    {
        if(levels[i] == level)
            j = i;
    }
    switch(j)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            Harl::debug();
            std::cout << std::endl;
            // fall through

        case 1:
            std::cout << "[ INFO ]" << std::endl;
            Harl::info();
            std::cout << std::endl;
            // fall through

        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            Harl::warning();
            std::cout << std::endl;
            // fall through

        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            Harl::error();
            std::cout << std::endl;
            break;

        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
    return ;
}