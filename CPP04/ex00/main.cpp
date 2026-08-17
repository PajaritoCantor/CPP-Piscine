/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:43:02 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/17 01:11:39 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inc/Animal.hpp"
#include "Inc/Dog.hpp"
#include "Inc/Cat.hpp"
#include "Inc/WrongAnimal.hpp"
#include "Inc/WrongCat.hpp"

int main()
{
    std::cout << "========== SUBJECT TESTS ==========" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << "\n--- Types ---" << std::endl;
    std::cout << "j is a: " << j->getType() << " " << std::endl;
    std::cout << "i is a: " << i->getType() << " " << std::endl;

    std::cout << "\n--- Sounds ---" << std::endl;
    j->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n--- Deletion ---" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "\n========== WRONG ANIMAL TESTS ==========" << std::endl;
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongI = new WrongCat();

    std::cout << "\n--- Types ---" << std::endl;
    std::cout << "wrongI is a: " << wrongI->getType() << " " << std::endl;

    std::cout << "\n--- Sounds ---" << std::endl;
    // This will call the WrongAnimal function because makeSound is NOT virtual
    wrongI->makeSound();
    wrongMeta->makeSound();

    std::cout << "\n--- Deletion ---" << std::endl;
    delete wrongMeta;
    delete wrongI;

    std::cout << "\n========== EXTRA TESTS ==========" << std::endl;
    std::cout << "--- Testing direct instantiation ---" << std::endl;
    Cat realCat;
    realCat.makeSound();

    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    Cat clonedCat(realCat);
    clonedCat.makeSound();

    std::cout << "\n--- End of Program ---" << std::endl;
}