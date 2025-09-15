/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:03:52 by madel-va          #+#    #+#             */
/*   Updated: 2025/08/07 20:03:52 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
    protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

    public:
    ClapTrap();
    ClapTrap(const std::string& name, int hp, int energy, int attack); //Constructor con parámetros
    ClapTrap(const std::string& name); //Constructor con nombre
    ClapTrap(const ClapTrap& other); // Constructor por copia
    ClapTrap& operator=(const ClapTrap& other); // Operador de asignación
    ~ClapTrap();   //Destructor

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif