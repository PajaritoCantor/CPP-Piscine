/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 02:19:47 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/17 03:32:01 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inc/Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain; // Instantiating its own brain
    std::cout << "[Dog] Default constructor called." << std::endl;
}
Dog::Dog(const Dog &other) : AAnimal(other)
{
    std::cout << "[Dog] Copy constructor called." << std::endl;
    this->brain = new Brain(*other.brain); // DEEP COPY: New Brain copying the content of the other.
}
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "[Dog] Assignment operator called." << std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "[Dog] Destructor called." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "[Dog] Woof! Woof! 🐕" << std::endl;
}

Brain *Dog::getBrain() const
{
    return this->brain;
}
