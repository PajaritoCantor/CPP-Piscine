/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:52:11 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/07 19:40:29 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	// New constructors required by the subject
	Fixed(const int n);
	Fixed(const float f);

	// Conversion methods
	float toFloat(void) const;
	int toInt(void) const;

	// Adittional member functions required
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

// Insertion operator overloading (outside the class)
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
