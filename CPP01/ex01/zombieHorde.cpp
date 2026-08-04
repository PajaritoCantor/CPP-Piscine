/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 16:34:03 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/04 17:20:23 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name)
{
    // 1. Bulk allocation: We create N zombie on the heap.
    // This automatically calls Zombie() N times.
    Zombie *horde = new Zombie[N];

    // 2. Baptism: We move through the horde and user our public window.
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    // 3. Map: We return the pointer (the coordinates of the first zombie)
    return horde;
}