/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:21:45 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/03 18:22:44 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
              << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n"
              << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n"
              << std::endl;
}

void Harl::complain(std::string level)
{
    // 1. Array con los niveles de queja en formato texto
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // 2. Array de PUNTEROS A FUNCIONES MIEMBRO
    // Sintaxis: tipo_retorno (Clase::*nombre_array[])(parametros)
    void (Harl::*funcs[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    // 3. El bucle que reemplaza al bosque de if/else
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            // Ejecutamos la función a través del puntero
            (this->*funcs[i])();
            return; // Rompemos la ejecución para que no siga buscando
        }
    }

    // (Opcional) Si Harl recibe un nivel que no conoce
    std::cout << "[ UNKNOWN ] Harl murmura algo incomprensible." << std::endl;
}