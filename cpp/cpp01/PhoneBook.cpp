/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:30:18 by aprivalo          #+#    #+#             */
/*   Updated: 2026/09/18 15:44:00 by aprivalo         ###   ########.fr       */
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

void Contact::setFirstName(std::string const &Value){FirstName = Value;}
std::string Contact::getFirstName() const {return FirstName; }

void Contact::setLastName(std::string const &Value){LastName = Value;}
std::string Contact::getLastName() const {return LastName;}

void Contact::setNickName(std::string const &Value){NickName = Value;}
std::string Contact::getNickName() const{return NickName;}

void Contact::setPhoneNumber(std::string const &Value){PhoneNumber = Value;}
std::string Contact::getPhoneNumber() const{return PhoneNumber;}

void Contact::setDarkestSecret(std::string const &Value){DarkestSecret = Value;}
std::string Contact::getDarkestSecret() const{return DarkestSecret;}

std::string getField(std::string const &prompt)
{
    std::string value;
    do {
        std::
    }
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    std::string cmd;
    std::getline(std::cin, cmd);
    while(std::getline(std::cin, cmd))
    {
        if(cmd == "ADD")
        {
            std::string FirstName;
            do {
                std::cout << "First name: ";
                std::getline(std::cin, FirstName);
            }   while(FirstName.empty());
            if(!std::getline(std::cin, cmd))
                break ;
        }
        else if(cmd == "SEARCH")
        {
            
        }
        else if(cmd == "EXIT")
        {
            break ;
        }
    }
}

