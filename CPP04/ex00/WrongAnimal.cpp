/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 21:45:09 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/16 22:21:50 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "[WrongAnimal] Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "[WrongAnimal] Copy constructor called." << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "[WrongAnimal] Assignment operator called." << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] Destructor called." << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "[WrongAnimal] * Wrong and weird alien sound *" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}