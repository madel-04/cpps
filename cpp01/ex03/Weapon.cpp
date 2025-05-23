/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:11:09 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/15 17:11:09 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 Implement a Weapon class that has:
 • Aprivate attribute type, which is a string.
 • AgetType() member function that returns a constant reference to type.
 • AsetType() member function that sets type using the new value passed as a pa
rameter.
*/

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {}

const std::string &Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string &type) {
    _type = type;
}