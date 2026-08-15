/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:00:09 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/15 19:34:10 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor por defecto
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " has been created! (Default constructor)" << std::endl;
}

// Constructor con nombre
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

// Constructor de copia
ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

// Operador de asignación
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

// Función de ataque
void ClapTrap::attack(const std::string& target) {
    if (this->_hitPoints > 0 && this->_energyPoints > 0) {
        std::cout << "ClapTrap " << this->_name << " attacks " << target 
                  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    } else {
        std::cout << "ClapTrap " << this->_name << " cannot attack. Not enough Hit points or Energy points!" << std::endl;
    }
}

// Función para recibir daño
void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints > 0) {
        if (amount > this->_hitPoints)
            this->_hitPoints = 0;
        else
            this->_hitPoints -= amount;
        
        std::cout << "ClapTrap " << this->_name << " takes " << amount 
                  << " points of damage! Hit points left: " << this->_hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << this->_name << " is already destroyed and cannot take more damage!" << std::endl;
    }
}

// Función para repararse
void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints > 0 && this->_energyPoints > 0) {
        this->_hitPoints += amount;
        this->_energyPoints--;
        std::cout << "ClapTrap " << this->_name << " repairs itself, gaining " << amount 
                  << " Hit points! Current Hit points: " << this->_hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << this->_name << " cannot be repaired. Not enough Hit points or Energy points!" << std::endl;
    }
}