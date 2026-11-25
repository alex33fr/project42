/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 12:04:24 by aprivalo          #+#    #+#             */
/*   Updated: 2026/09/30 22:31:23 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::~Zombie( void )
{
    std::cout << _name << " is dead!" << std::endl;
}

void Zombie::announce( void ) const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
