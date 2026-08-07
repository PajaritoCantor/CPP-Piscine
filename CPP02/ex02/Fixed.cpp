/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:51:53 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/07 20:02:04 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// --- ORTHODOX CANONICAL FORM ---
Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

// --- CONSTRUCTORS AND CONVERSIONS ---
Fixed::Fixed(const int n)
{
    this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
    this->_fixedPointValue = roundf(f * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

// --- COMPARISON OPERATORS ---
bool Fixed::operator>(const Fixed &other) const { return this->getRawBits() > other.getRawBits(); }
bool Fixed::operator<(const Fixed &other) const { return this->getRawBits() < other.getRawBits(); }
bool Fixed::operator>=(const Fixed &other) const { return this->getRawBits() >= other.getRawBits(); }
bool Fixed::operator<=(const Fixed &other) const { return this->getRawBits() <= other.getRawBits(); }
bool Fixed::operator==(const Fixed &other) const { return this->getRawBits() == other.getRawBits(); }
bool Fixed::operator!=(const Fixed &other) const { return this->getRawBits() != other.getRawBits(); }

// --- ARITHMETIC OPERATORS ---
Fixed Fixed::operator+(const Fixed &other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed &other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const { return Fixed(this->toFloat() / other.toFloat()); }

// --- INCREMENT / DECREMENT OPERATORS ---
Fixed &Fixed::operator++()
{
    this->_fixedPointValue++; // Pre-increment
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this); // Post-increment (saves current state)
    this->_fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->_fixedPointValue--; // Pre-decrement
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this); // Post-decrement (saves current state)
    this->_fixedPointValue--;
    return temp;
}

// --- STATIC MEMBER FUNCTIONS ---
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

// --- INSERTION OPERATOR ---
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}