/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:00:52 by jurodrig          #+#    #+#             */
/*   Updated: 2026/07/30 19:15:47 by jurodrig         ###   ########.fr       */
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
    Zombie(std::string name);
    ~Zombie();

    void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
