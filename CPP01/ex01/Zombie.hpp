/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 16:22:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/03 17:09:11 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
    std::string _name;

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    void announce(void);
    void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif