/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:47:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/17 01:10:02 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inc/Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "[Dog] Default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "[Dog] Copy constructor called." << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "[Dog] Assignment operator called." << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "[Dog] Destructor called." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "[Dog] Woof! Woof! 🐕" << std::endl;
}