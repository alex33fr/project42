/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:30:18 by aprivalo          #+#    #+#             */
/*   Updated: 2026/09/22 08:10:29 by aprivalo         ###   ########.fr       */
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

std::string Truncate(std::string const &s)
{
    if(s.length() > 10)
        return(s.substr(0, 9) + ".");
    return (s);
}
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
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;

    for (int i = 0; i < count && i < 8; i++)
    {
        std::stringstream idx;
        idx << i;
        std::cout << "|" << std::setw(10) << Truncate(idx.str())
                  << "|" << std::setw(10) << Truncate(contacts[i].getFirstName())
                  << "|" << std::setw(10) << Truncate(contacts[i].getLastName())
                  << "|" << std::setw(10) << Truncate(contacts[i].getNickName())
                  << "|" << std::endl;
    }
    if (count == 0)
        return ;

    std::cout << "Enter index to display: ";
    std::string input;
    if (!std::getline(std::cin, input))
        return ;
    std::istringstream iss(input);
    int index;
    if (!(iss >> index) || index < 0 || index >= count || index >= 8)
    {
        std::cout << "Invalid index." << std::endl;
        return ;
    }
    std::cout << "First name:     " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name:      " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname:       " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone number:   " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    std::string cmd;
    PhoneBook book;
    Contact contact;
    std::cout << "PhoneBook, use commands: ADD, SEARCH, EXIT" << std::endl;
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
            std::cout << "Account: " << FirstName << " created!" << std::endl;
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

