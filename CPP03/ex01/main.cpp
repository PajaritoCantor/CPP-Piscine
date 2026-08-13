/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 19:32:16 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/13 19:35:06 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- CONSTRUCTING SCAVTRAP ---" << std::endl;
    ScavTrap scav("Serena");

    std::cout << "\n--- TESTING OVERRIDDEN ATTACK ---" << std::endl;
    scav.attack("Target Dummy");

    std::cout << "\n--- TESTING INHERITED FUNCTIONS ---" << std::endl;
    scav.takeDamage(30);
    scav.beRepaired(10);

    std::cout << "\n--- TESTING SPECIAL ABILITY ---" << std::endl;
    scav.guardGate();

    std::cout << "\n--- DESTRUCTION CHAIN ---" << std::endl;
    return 0;
}