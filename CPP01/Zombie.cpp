/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:09:52 by jurodrig          #+#    #+#             */
/*   Updated: 2026/07/28 18:29:28 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name) : _name(name) {}

// Destructor
Zombie::~Zombie()
{
    std::cout << _name << " has been destroyed." << std::endl;
}

// Member function
void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzZ..." << std::endl;
}