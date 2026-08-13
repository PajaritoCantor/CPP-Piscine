/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 19:19:13 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/13 19:37:30 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor por defecto
ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap default constructor called." << std::endl;
}

// Constructor parametrizado
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " has been constructed!" << std::endl;
}

// Constructor de copia
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called." << std::endl;
    *this = other;
}

// Operador de asignación
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap assignment operator called." << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " has been destroyed!" << std::endl;
}

// Sobreescritura de attack
void ScavTrap::attack(const std::string &target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        this->_energyPoints--;
        std::cout << "ScavTrap " << this->_name << " viciously attacks " << target
                  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->_name << " has no energy or hit points left to attack!" << std::endl;
    }
}

// Habilidad especial
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}