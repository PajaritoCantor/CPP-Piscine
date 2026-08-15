/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:31:43 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/16 01:39:07 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main(){
    std::cout <<"\n--- CONSTRUCTING FRAGTRAP ---"<< std::endl;
    FragTrap frag("Claptrap's cooler brother");

    std::cout << "\n--- TESTING INHERITED FUNCTIONS ---" << std::endl;
    // usa el attack heredado de ClapTrap
    frag.attack("a random skag");
    frag.takeDamage(50);
    frag.beRepaired(25);

    std::cout << "\n--- TESTING SPECIAL ABILITY ---" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n--- DESTRUCTION CHAIN ---" << std::endl;
    return 0;
}