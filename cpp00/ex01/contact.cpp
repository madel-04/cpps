/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:01:53 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/14 20:01:53 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

bool Contact::setFirstName(const std::string &firstName) {
    if (firstName.empty()) {
        return false;
    }
    _firstName = firstName;
    return true;
}
bool Contact::setLastName(const std::string &lastName) {
    if (lastName.empty()) {
        return false;
    }
    _lastName = lastName;
    return true;
}
bool Contact::setNickname(const std::string &nickname) {
    if (nickname.empty()) {
        return false;
    }
    _nickname = nickname;
    return true;
}
bool Contact::setPhoneNumber(const std::string &phoneNumber) {
    if (phoneNumber.empty()) {
        return false;
    }
    _phoneNumber = phoneNumber;
    return true;
}
bool Contact::setDarkestSecret(const std::string &darkestSecret) {
    if (darkestSecret.empty()) {
        return false;
    }
    _darkestSecret = darkestSecret;
    return true;
}

const std::string &Contact::getFirstName() const { return _firstName; }
const std::string &Contact::getLastName() const { return _lastName; }
const std::string &Contact::getNickname() const { return _nickname; }
const std::string &Contact::getPhoneNumber() const { return _phoneNumber; }
const std::string &Contact::getDarkestSecret() const { return _darkestSecret; }
