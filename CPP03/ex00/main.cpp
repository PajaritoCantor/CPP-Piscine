/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 20:04:05 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/12 21:04:57 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    std::cout << "--- CREATING CLAPTRAPS ---" << std::endl;
    ClapTrap robot1("R2-D2");
    ClapTrap robot2("C-3PO");
    
    std::cout << "\n--- BASIC COMBAT TEST ---" << std::endl;
    robot1.attack("C-3PO");
    robot2.takeDamage(0); // Base Damage is 0
    
    robot2.beRepaired(5);
    
    std::cout << "\n--- EXHAUSTING DEPLETION TEST ---" << std::endl;
    // A Claptrap has 10 energy points; let's spend it all.
    for (int i = 0; i < 10; ++i) {
        robot1.attack("C-3PO");
    }
    
    // Este intento debe fallar porque ya no tiene energía
    robot1.beRepaired(10);
    
    std::cout << "\n--- TEST DE DESTRUCCION (DAÑO LETAL) ---" << std::endl;
    robot2.takeDamage(15); // Excede los HP actuales
    robot2.attack("R2-D2"); // Debe fallar porque no tiene HP
    
    std::cout << "\n--- DESTRUYENDO CLAPTRAPS (FIN DEL SCOPE) ---" << std::endl;
    return 0;
}