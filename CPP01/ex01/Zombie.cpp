/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 16:28:32 by jurodrig          #+#    #+#             */
/*   Updated: 2026/07/31 17:01:14 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Builder
Zombie::Zombie(std::string name) : _name(name) {}

// Destroyer
Zombie::~Zombie()
{
    std::cout << _name << " has been destroyed." << std::endl;
}

// Member function
void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzZ..." << std::endl;
}
Zombie::Zombie() {}

void Zombie::setName(std::string name)
{
    _name = name;
}
