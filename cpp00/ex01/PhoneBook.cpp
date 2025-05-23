/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:06:41 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/14 20:06:41 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip> 

PhoneBook::PhoneBook() : _count(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact &newContact) {
    int index = _count % 8;
    _contacts[index] = newContact;
    ++_count;
}


int PhoneBook::size() const {
    return (_count < 8 ? _count : 8);
}

static std::string truncateFmt(const std::string& s) {
    if (s.length() <= 10) return s;
    return s.substr(0, 9) + ".";
}

void PhoneBook::displayList() const {
    std::cout << std::setw(10) << "Index" << '|'
              << std::setw(10) << "First Name" << '|'
              << std::setw(10) << "Last Name"  << '|'
              << std::setw(10) << "Nickname"   << '\n';
    for (int i = 0; i < size(); ++i) {
        std::cout << std::setw(10) << i << '|'
                  << std::setw(10) << truncateFmt(_contacts[i].getFirstName()) << '|'
                  << std::setw(10) << truncateFmt(_contacts[i].getLastName())  << '|'
                  << std::setw(10) << truncateFmt(_contacts[i].getNickname())  << '\n';
    }
}

bool PhoneBook::displayContact(int index) const {
    if (index < 0 || index >= size()) return false;
    const Contact& c = _contacts[index];
    std::cout << "First Name:   " << c.getFirstName()    << '\n'
              << "Last Name:    " << c.getLastName()     << '\n'
              << "Nickname:     " << c.getNickname()     << '\n'
              << "Phone Number: " << c.getPhoneNumber()  << '\n'
              << "Darkest Secret: " << c.getDarkestSecret() << '\n';
    return true;
}
