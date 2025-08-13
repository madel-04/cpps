/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:03:09 by madel-va          #+#    #+#             */
/*   Updated: 2025/08/07 20:03:09 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

#include "DiamondTrap.hpp"

int main() {
    DiamondTrap dt("BlingBling");

    dt.attack("Enemy");
    dt.highFivesGuys();
    dt.guardGate();
    dt.whoAmI();

    return 0;
}
