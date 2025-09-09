/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:36:47 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/15 12:36:47 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("") {}

Zombie::Zombie(const std::string &name) : _name(name) {}

Zombie::~Zombie()
{
    std::cout << _name << " destroyed\n";
}

void Zombie::setName(const std::string &name)
{
    _name = name;
}

void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n"<< std::endl;
}

