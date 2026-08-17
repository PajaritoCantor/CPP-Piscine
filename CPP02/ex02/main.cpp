/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 20:03:06 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/11 18:09:37 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

// Auxiliary function for print a especific block bits
void printBits(unsigned int num, int startBit, int endBit)
{
    for (int i = startBit; i >= endBit; --i)
    {
        std::cout << ((num >> i) & 1);
    }
}

void floatingVSfixed_Anatomytest(float test_number)
{
    std::cout << "========================================\n";
    std::cout << "ANALIZING THE NUMBER: " << test_number << "\n";
    std::cout << "========================================\n";

    // 1. EXTRACTING FLOAT BITS (IEEE 754)
    unsigned int raw_float_bits = *(reinterpret_cast<unsigned int *>(&test_number));

    std::cout << "[FLOTANTE IN CPU - IEEE 754]\n";
    std::cout << "Sign (1 bit): ";
    printBits(raw_float_bits, 31, 31);
    std::cout << "\nExponent (8 bits):";
    printBits(raw_float_bits, 30, 23);
    std::cout << "\nMantissa (23 bits):";
    printBits(raw_float_bits, 22, 0);
    std::cout << "\n\nRaw cpu memory: ";
    printBits(raw_float_bits, 31, 31);
    std::cout << " | ";
    printBits(raw_float_bits, 30, 23);
    std::cout << " | ";
    printBits(raw_float_bits, 22, 0);
    std::cout << "\n\n";

    // 2. EXTRACT FIXED POINT BITS (My Fixed class)
    Fixed fixed(test_number);
    unsigned int raw_fixed_bits = fixed.getRawBits();

    std::cout << "[FIXED POINT IN MY CLASS FIXED]\n";
    std::cout << "saved decimal value: " << raw_fixed_bits << "\n";
    std::cout << "Integer (24 bits)  : ";
    printBits(raw_fixed_bits, 31, 8);
    std::cout << "\nFraction (8 bits) : ";
    printBits(raw_fixed_bits, 7, 0);
    std::cout << "\n\nRaw CPU memory : ";
    printBits(raw_fixed_bits, 31, 8);
    std::cout << " | ";
    printBits(raw_fixed_bits, 7, 0);
    std::cout << "\n========================================\n";
}

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    // New variables to aritmetics and comparison tests
    Fixed c(10.5f);
    Fixed d(2.0f);

    std::cout << "\n--- 1. INCREMENT AND DECREMENT TESTS ---" << std::endl;
    std::cout << "first a : " << a << std::endl;
    std::cout << "++a       : " << ++a << std::endl;
    std::cout << "a         : " << a << std::endl;
    std::cout << "a++       : " << a++ << std::endl;
    std::cout << "a         : " << a << std::endl;
    std::cout << "--a       : " << --a << std::endl;
    std::cout << "a         : " << a << std::endl;
    std::cout << "a--       : " << a-- << std::endl;
    std::cout << "a         : " << a << std::endl;

    std::cout << "\n--- 2. ARITMETIC OPERATOR TESTS ---" << std::endl;
    std::cout << "c value: " << c << " | d value: " << d << std::endl;
    std::cout << "Addition (c + d)  : " << c + d << std::endl;
    std::cout << "Substraction (c - d) : " << c - d << std::endl;
    std::cout << "Mult (c * d) : " << c * d << std::endl;
    std::cout << "Div (c / d) : " << c / d << std::endl;

    std::cout << "\n--- 3. COMPARISON OPERATORS TESTS ---" << std::endl;
    // std::boolalpha makes cout print "true/false" instead "1/0"
    std::cout << std::boolalpha;
    std::cout << "c > d  : " << (c > d) << std::endl;
    std::cout << "c < d  : " << (c < d) << std::endl;
    std::cout << "c >= d : " << (c >= d) << std::endl;
    std::cout << "c <= d : " << (c <= d) << std::endl;
    std::cout << "c == d : " << (c == d) << std::endl;
    std::cout << "c != d : " << (c != d) << std::endl;
    std::cout << std::noboolalpha; // We restore normal output.

    std::cout << "\n--- 4. STATIC FUNCTION TESTS (MAX AND MIN) ---" << std::endl;
    std::cout << "b constant: " << b << std::endl;
    std::cout << "Max(a, b) (Call to const version)   : " << Fixed::max(a, b) << std::endl;
    std::cout << "Min(a, b) (Call to const version)   : " << Fixed::min(a, b) << std::endl;
    std::cout << "Max(c, d) (Call to normal version)  : " << Fixed::max(c, d) << std::endl;
    std::cout << "Min(c, d) (Call to normal version)  : " << Fixed::min(c, d) << std::endl;

    std::cout << "\n--- 5. VISUAL MEMORY TEST ---" << std::endl;
    floatingVSfixed_Anatomytest(42.25f);

    std::cout << "\n--- MATHEMATICS TEST: SETRAWBITS ---" << std::endl;
    Fixed hacker_obj; // It starts at 0

    std::cout << "initial object " << hacker_obj << std::endl;

    // We inject 256 raw. Mathematically, this is 256 / (2^8) = 1.0.
    std::cout << "Injecting raw bits: 256 " << std::endl;
    hacker_obj.setRawBits(256);
    std::cout << "Current value of the object " << hacker_obj << std::endl;

    // We inject 128 in raw form. Mathematically, this is 128 / (2^8) = 0.5.
    std::cout << "Injecting raw bits: 128 " << std::endl;
    hacker_obj.setRawBits(128);
    std::cout << "Current value of the object " << hacker_obj << std::endl;

    return 0;
}