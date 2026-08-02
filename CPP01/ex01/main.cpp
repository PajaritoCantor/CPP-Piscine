/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 16:51:09 by jurodrig          #+#    #+#             */
/*   Updated: 2026/07/31 16:59:55 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// We declare the function so that main know it exists
Zombie *zombieHorde(int N, std::string name);

int main()
{
    int n = 5;

    std::cout << "---CREATING THE HORDE ---" << std::endl;
    // We receive the map to the 5 zombis
    Zombie *myHorde = zombieHorde(n, "Walker");

    std::cout << "\n--- THE HORDE ATTACKS" << std::endl;
    // we make them scream one by one
    for (int i = 0; i < n; i++)
    {
        myHorde[i].announce();
    }
    std::cout << "\n--- DESTROYING THE HORDE ---" << std::endl;
    // MANDATORY: Use delete square brackets [] because they were created with 'new'
    delete[] myHorde;

    return 0;
}
