/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:14:41 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/07 19:44:37 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    // We use the assignment operator to copy the data.
    // The Subject indicates that the assignment message may or may not appear here depending the implementation
    // depending the implementation
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
// --- NEW CONSTRUCTOR ---

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    // We shift the bits to the left to make room for the fractional bits.
    this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    // We multiply by 2^8 (256) and round to the nearest integer.
    this->_fixedPointValue = roundf(f * (1 << _fractionalBits));
}
// --- CONVERSION METHODS ---

float Fixed::toFloat(void) const
{
    // We divide the raw value by 256.0 to recover the decimal values.
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    // We shift to the right to eliminate the fractional bits.
    return this->_fixedPointValue >> _fractionalBits;
}

// --- GETTERS Y SETTERS ---

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
// --- INSERTION OPERATOR OVERLOAD ---
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    // Insert the floating-point representation into the output stream.
    os << fixed.toFloat();
    return os;
}