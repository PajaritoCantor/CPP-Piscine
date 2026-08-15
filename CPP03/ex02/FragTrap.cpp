/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 22:58:37 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/16 01:37:49 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default Constructor
FragTrap::FragTrap() : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap default constructor called for an unnamed robot.";
}

// Named Constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name){
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " arrives to the battlefield, ready to party!" << std::endl;
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
    std::cout << "FragTrap copy constructor called." << std::endl;
    *this = other;    
}

// Assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other){
    std::cout << "FragTrap assignment operator called." << std::endl;
    if (this != &other){
        this->_name = other._name;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
        }
    return *this;
}

// Deestructor
FragTrap::~FragTrap(){
    std::cout << "FragTrap " << this->_name << " has been destroyed! No more high fives..." << std::endl;
}

// Habilidad especial
void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap " << this->_name << " enthusiastically asks: \"GIMME A HIGH FIVE, GUYS ✋\"" << std::endl;
}