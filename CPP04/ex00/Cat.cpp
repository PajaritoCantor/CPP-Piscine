/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 21:00:35 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/17 01:21:03 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inc/Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "[Cat] Default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "[Cat] Copy constructor called." << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "[Cat] Assignment operator called." << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "[Cat] Destructor called." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow! Meow! 🐈" << std::endl;
}