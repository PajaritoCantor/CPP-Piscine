/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 02:07:25 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/17 03:47:36 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inc/Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "";
    std::cout << "[Brain] Default constructor called." << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "[Brain] Copy constructor called." << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "[Brain] Assignment operator called." << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "[Brain] Destructor called." << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}
std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return this->ideas[index];
    return "";
}
