/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:49:36 by jurodrig          #+#    #+#             */
/*   Updated: 2026/07/29 15:54:48 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Allocates a Zombie on the heap
// It will persist in memor until you explicitily call 'delete' on it.
Zombie *newZombie(std::string name)
{
    return new Zombie(name);
}