/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:22:30 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/03 18:22:45 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
private:
    // Funciones privadas requeridas por el subject
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    Harl();
    ~Harl();

    // Función pública para hacer que Harl se queje
    void complain(std::string level);
};

#endif