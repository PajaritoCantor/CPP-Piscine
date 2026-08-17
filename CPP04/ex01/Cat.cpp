/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 21:00:35 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/17 03:47:36 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inc/Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "[Cat] Default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "[Cat] Copy constructor called." << std::endl;
    this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "[Cat] Assignment operator called." << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "[Cat] Destructor called." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow! Meow! 🐈" << std::endl;
}

Brain *Cat::getBrain() const
{
    return this->brain;
}