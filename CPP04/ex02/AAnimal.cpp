/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 03:09:01 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/17 03:27:28 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inc/AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "[AAnimal] Default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << "[AAnimal] Copy constructor called." << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    std::cout << "[AAnimal] Assignment operator called." << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "[AAnimal] Destructor called." << std::endl;
}

std::string AAnimal::getType() const
{
    return this->type;
}
