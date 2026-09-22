/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:32:13 by aprivalo          #+#    #+#             */
/*   Updated: 2026/09/22 07:45:20 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Contact
{
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
    public:
    Contact();
    ~Contact();
    
    void setFirstName(std::string const &FirstName);
    std::string getFirstName() const;

    void setLastName(std::string const &LastName);
    std::string getLastName() const;

    void setNickName(std::string const &NickName);
    std::string getNickName() const;

    void setPhoneNumber(std::string const &PhoneNumber);
    std::string getPhoneNumber() const;

    void setDarkestSecret(std::string const &DarkestSecret);
    std::string getDarkestSecret() const;
};

class PhoneBook
{
    private:
        Contact contacts[8];
        int count;
    public:
        void AddContact(Contact const &contact);
        void SearchContact() const;
    PhoneBook();
    ~PhoneBook();
};

# endif 