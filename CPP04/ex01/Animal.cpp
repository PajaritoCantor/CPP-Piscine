/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 01:59:41 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/17 01:11:04 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inc/Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "[Animal] Default constructor called." << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "[Animal] Copy constructor called." << std::endl;
    *this = other;
}
Animal &Animal::operator=(const Animal &other)
{
    std::cout << "[Animal] Assignment operator called." << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "[Animal] Destructor called." << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "[Animal] * Unrecognizable generic animal sound **" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}