/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 20:03:06 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/07 20:03:09 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

// Auxiliary function for print a especific block bits
void printBits(unsigned int num, int startBit, int endBit) {
    for (int i = startBit; i >= endBit; --i) {
        std::cout << ((num >> i) & 1);
    }
}

void floatingVSfixed_Anatomytest(float test_number) {
    std::cout << "========================================\n";
    std::cout << "ANALIZING THE NUMBER: " << test_number << "\n";
    std::cout << "========================================\n";

    // 1. EXTRACTING FLOAT BITS (IEEE 754)
    unsigned int raw_float_bits = *(reinterpret_cast<unsigned int*>(&test_number));

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
    
    // Nuevas variables para pruebas aritméticas y de comparación
    Fixed c(10.5f);
    Fixed d(2.0f);

    std::cout << "\n--- 1. PRUEBAS DE INCREMENTO Y DECREMENTO ---" << std::endl;
    std::cout << "a inicial : " << a << std::endl;
    std::cout << "++a       : " << ++a << std::endl;
    std::cout << "a         : " << a << std::endl;
    std::cout << "a++       : " << a++ << std::endl;
    std::cout << "a         : " << a << std::endl;
    std::cout << "--a       : " << --a << std::endl;
    std::cout << "a         : " << a << std::endl;
    std::cout << "a--       : " << a-- << std::endl;
    std::cout << "a         : " << a << std::endl;

    std::cout << "\n--- 2. PRUEBAS DE OPERADORES ARITMÉTICOS ---" << std::endl;
    std::cout << "Valor de c: " << c << " | Valor de d: " << d << std::endl;
    std::cout << "Suma (c + d)  : " << c + d << std::endl;
    std::cout << "Resta (c - d) : " << c - d << std::endl;
    std::cout << "Multi (c * d) : " << c * d << std::endl;
    std::cout << "Divis (c / d) : " << c / d << std::endl;

    std::cout << "\n--- 3. PRUEBAS DE OPERADORES DE COMPARACIÓN ---" << std::endl;
    // std::boolalpha obliga a cout a imprimir "true/false" en lugar de "1/0"
    std::cout << std::boolalpha; 
    std::cout << "c > d  : " << (c > d) << std::endl;
    std::cout << "c < d  : " << (c < d) << std::endl;
    std::cout << "c >= d : " << (c >= d) << std::endl;
    std::cout << "c <= d : " << (c <= d) << std::endl;
    std::cout << "c == d : " << (c == d) << std::endl;
    std::cout << "c != d : " << (c != d) << std::endl;
    std::cout << std::noboolalpha; // Restauramos la salida normal

    std::cout << "\n--- 4. PRUEBAS DE FUNCIONES ESTÁTICAS (MAX Y MIN) ---" << std::endl;
    std::cout << "b constante: " << b << std::endl;
    std::cout << "Max(a, b) (Llama version const)   : " << Fixed::max(a, b) << std::endl;
    std::cout << "Min(a, b) (Llama version const)   : " << Fixed::min(a, b) << std::endl;
    std::cout << "Max(c, d) (Llama version normal)  : " << Fixed::max(c, d) << std::endl;
    std::cout << "Min(c, d) (Llama version normal)  : " << Fixed::min(c, d) << std::endl;

    std::cout << "\n--- 5. PRUEBA VISUAL DE MEMORIA ---" << std::endl;
    floatingVSfixed_Anatomytest(42.25f);
    
    return 0;
}