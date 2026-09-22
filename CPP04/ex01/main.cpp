/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 02:31:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/17 14:40:29 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inc/Animal.hpp"
#include "Inc/Dog.hpp"
#include "Inc/Cat.hpp"
#include "Inc/Brain.hpp"

#define ARRAY_SIZE 4

int main()
{
    std::cout << "========== ARRAY OF ANIMALS TEST ==========" << std::endl;
    Animal *animals[ARRAY_SIZE];

    // Fill half of the array with Dogs and the other half with Cats
    for (int i = 0; i < ARRAY_SIZE / 2; i++)
    {
        std::cout << "\n--- Creating Dog " << i << " ---" << std::endl;
        animals[i] = new Dog();
    }
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++)
    {
        std::cout << "\n--- Creating Cat " << i << " ---" << std::endl;
        animals[i] = new Cat();
    }

    std::cout << "\n--- Making Sounds ---" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        animals[i]->makeSound(); // Polymorphism ensures the correct sound is played
    }

    std::cout << "\n--- Deleting Animals ---" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        delete animals[i]; // Virtual destructor ensures the correct destruction sequence
    }

    std::cout << "\n========== DEEP COPY TEST ==========" << std::endl;
    Dog basicDog;
    basicDog.getBrain()->setIdea(0, "I want a bone!");

    std::cout << "\n--- Copying Dog ---" << std::endl;
    Dog copyDog = basicDog; // Calls the copy constructor

    std::cout << "\n--- Modifying Copy ---" << std::endl;
    copyDog.getBrain()->setIdea(0, "I want to chase a squirrel!");

    std::cout << "\n--- Checking Ideas ---" << std::endl;
    std::cout << "Basic Dog Idea: " << basicDog.getBrain()->getIdea(0) << std::endl; // Should remain "I want a bone!"
    std::cout << "Copy Dog Idea:  " << copyDog.getBrain()->getIdea(0) << std::endl;  // Should be "I want to chase a squirrel!"

    std::cout << "\n--- End of Scope (Destructors for basicDog and copyDog) ---" << std::endl;
    return 0;
}
