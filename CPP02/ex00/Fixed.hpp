/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:15:01 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/07 19:10:29 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	// 1. Default Constructor
	Fixed();

	// 2. Copy Constructor
	Fixed(const Fixed &other);

	// 3. Copy assignment operator overloading
	Fixed &operator=(const Fixed &other);

	// 4. Destructor
	~Fixed();

	// Adittional member functions required
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
