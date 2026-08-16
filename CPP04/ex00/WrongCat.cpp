/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 22:26:09 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/16 22:32:09 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "[WrongCat] Default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "[WrongCat] copy constructor called." << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "[WrongCat] Assignment operator called." << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] Destructor called." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "[WrongCat] Wrong meow! 😼" << std::endl;
}
