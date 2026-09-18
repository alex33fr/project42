#include <iostream>
#include <cctype>
#include <string>
/**
 * @brief
 * Toupper input message
 * @param ac 
 * @param av 
 * @return int = 1 for ignore name of program 
 */

int main(int ac, char **av)
{
    if(ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (1);
    }
    else
    {
        for (int i = 1; i < ac; i++)
        {
            std::string tab = av[i];
            char res;
            for (size_t j = 0; j < tab.length(); j++)
            {
                res = toupper(tab[j]);
                std::cout << res;
            }
        }
        std::cout << "\n";
    }
    return (0);
}