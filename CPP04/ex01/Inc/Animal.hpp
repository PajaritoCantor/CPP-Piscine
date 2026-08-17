/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 02:01:23 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/17 02:19:26 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type; // Protected attribute requested by the subject

public:
    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal(); // It is essential that it be virtual

    virtual void makeSound() const;
    std::string getType() const;
};

#endif