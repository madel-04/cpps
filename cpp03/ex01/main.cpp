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
#include <iostream>

int main() {
    std::cout << "=== Local scope test ===" << std::endl;
    {
        ScavTrap s1("Optimus");
        ScavTrap s2 = s1; // copy
        s1.attack("Decepticon");
        s2.takeDamage(30);
        s2.beRepaired(10);
        s1.guardGate();
    } // aquí deben verse: ~ScavTrap de s2/s1 y luego ~ClapTrap en orden inverso de construcción

    std::cout << "\n=== Dynamic test (delete via base pointer) ===" << std::endl;
    ClapTrap* p = new ScavTrap("Bumblebee");
    p->attack("target"); // si attack es virtual se llamará a ScavTrap::attack
    delete p; // si ~ClapTrap es virtual, se llamará a ~ScavTrap y luego ~ClapTrap
    return 0;
}
