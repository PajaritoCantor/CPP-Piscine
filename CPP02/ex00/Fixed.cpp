/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:14:41 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/06 19:25:20 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// 1. Default Constructor.
Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// 2. Copy Constructor.
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    // We use the assignment operator to copy the data.
    // The Subject indicates that the assignment message may or may not appear here depending the implementation
    // depending the implementation
    *this = other;
}

// 3. Copy assignment operator overloading.
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

// 4. Destructor.
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Return the raw value of the fixed-point number
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

// Sets the raw value of the fixed-point number.
void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}