/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 03:00:53 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/17 03:27:25 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal &other);
    AAnimal &operator=(const AAnimal &other);
    virtual ~AAnimal();

    virtual void makeSound() const = 0;

    std::string getType() const;
};

#endif