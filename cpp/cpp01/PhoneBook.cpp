/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:30:18 by aprivalo          #+#    #+#             */
/*   Updated: 2026/09/18 08:19:04 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count (0)
{
}

PhoneBook::~PhoneBook()
{
}

Contact::Contact() 
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(std::string const &Value)
{
    FirstName = Value;
}
std::string Contact::getFirstName() const
{
    return FirstName;
}

void Contact::setLastName(std::string const &Value)
{
    LastName = Value;
}
std::string Contact::getLastName() const
{
    return LastName;
}

void Contact::setNickName(std::string const &Value)
{
    NickName = Value;
}
std::string Contact::getNickName() const
{
    return NickName;
}

void Contact::setPhoneNumber(std::string const &Value)
{
    PhoneNumber = Value;
}
std::string Contact::getPhoneNumber() const
{
    return PhoneNumber;
}

void Contact::setDarkestSecret(std::string const &Value)
{
    DarkestSecret = Value;
}
std::string Contact::getDarkestSecret() const
{
    return DarkestSecret;
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    while(1)
    {
    }
}

