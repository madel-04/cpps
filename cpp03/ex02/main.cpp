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

int main() {
    std::cout << "=== FragTrap test ===" << std::endl;
    {
        FragTrap f1("Goku");
        FragTrap f2(f1); // constructor copia
        f1.attack("Vegeta");
        f2.highFivesGuys();
    } // aquí se ven destructores en orden inverso

    std::cout << "\n=== Dynamic allocation test ===" << std::endl;
    ClapTrap* f = new FragTrap("Vegeta");
    f->attack("Freezer"); // se usa la versión override
    delete f; // destructor virtual asegura limpieza correcta
}