/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:30:18 by aprivalo          #+#    #+#             */
/*   Updated: 2026/09/21 15:55:12 by aprivalo         ###   ########.fr       */
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

std::string getField(std::string const &UserInput)
{
    std::string value;
    do {
        std::cout << UserInput;
        if(!std::getline(std::cin, value))
            return ("");
    }   while (value.empty());
    return (value);
}

void PhoneBook::AddContact(Contact const &contact)
{
    contacts[count % 8] = contact;
    count++;
}

void PhoneBook::SearchContact() const
{
    int i = 0;
    std::cout << "Index " << "First Name " << "Last Name" << "NickName" << std::endl;
    while (i < count && i < 8)
    {
        std::cout << i << contacts[i].getFirstName() << contacts[i].getLastName() << contacts[i].getNickName() << std::endl;
        i++;
    }
    
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    std::string cmd;
    PhoneBook book;
    Contact contact;
    while(std::getline(std::cin, cmd))
    {
        if(cmd == "ADD")
        {
            std::string FirstName = getField("First name: ");
            if(FirstName.empty())
                break ;
            std::string LastName = getField("Last name: ");
            if(LastName.empty())
                break ;
            std::string NickName = getField("Nick name: ");
            if(NickName.empty())
                break ;
            std::string PhoneNumber = getField("Phone number: ");
            if(PhoneNumber.empty())
                break ;
            std::string DarkestSecret = getField("Darkest Secret: ");
            if(DarkestSecret.empty())
                break ;
            
            contact.setFirstName(FirstName);
            contact.setLastName(LastName);
            contact.setNickName(NickName);
            contact.setPhoneNumber(PhoneNumber);
            contact.setDarkestSecret(DarkestSecret);
            book.AddContact(contact);
        }
        else if(cmd == "SEARCH")
        {
            book.SearchContact();
        }
        else if(cmd == "EXIT")
        {
            break ;
        }
    }
}

