/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 22:28:03 by aprivalo          #+#    #+#             */
/*   Updated: 2026/10/01 12:53:09 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <sstream>

int main(int ac, char **av)
{
    int     max_Zombie;
    char    rest;
    Zombie* horde;

    if (ac != 2)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return (1);
    }

    std::istringstream iss(av[1]);
    if (!(iss >> max_Zombie) || (iss >> rest)
        || max_Zombie < 1 || max_Zombie > 1000)
    {
        std::cerr << "Error: Invalid number of zombies." << std::endl;
        return (1);
    }

    horde = zombieHorde(max_Zombie, "Soldat");
    for (int i = 0; i < max_Zombie; i++)
    {
        std::cout << i + 1 << ": ";
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}
