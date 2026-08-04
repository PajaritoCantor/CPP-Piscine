/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/08/04 17:10:45 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType() const
{
    return this->type;
}

void Weapon::setType(const std::string &type)
{
    this->type = type;
}
