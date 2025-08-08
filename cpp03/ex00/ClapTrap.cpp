/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:07:17 by madel-va          #+#    #+#             */
/*   Updated: 2025/08/07 20:07:17 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Constructor por defecto
ClapTrap::ClapTrap()
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructed (default)." << std::endl;
}

//Constructor con nombre
ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap" << _name << "constructed." << std::endl;
}

// Constructor por copia
ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "ClapTrap " << _name << " copy constructed." << std::endl;
}

// Operador de asignación
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << _name << " assigned." << std::endl;
    return *this;
}

//Destructor
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap" << _name << "destroyed" << std::endl;
}

// Métodos
void ClapTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " can't attack (no energy or dead)." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
        return;
    }
    _hitPoints -= amount;
    if (_hitPoints < 0) _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage! HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount
                  << " HP. Total HP: " << _hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " can't repair (no energy or dead)." << std::endl;
    }
}