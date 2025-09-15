/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:22:05 by madel-va          #+#    #+#             */
/*   Updated: 2025/08/08 19:22:05 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("Default", 100, 50, 20)
{
    std::cout << "ScavTrap " << _name << " constructed (default)." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap " << _name << " constructed (custom name)." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " copy constructed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other); //realiza operador de la base
    }
    std::cout << "ScavTrap " << _name << " assigned." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destroyed." << std::endl;
}

void ScavTrap::guardGate() const
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
