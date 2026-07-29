/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 17:25:05 by jurodrig          #+#    #+#             */
/*   Updated: 2026/07/29 17:41:04 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << "--- Testing Stack Allocation ---" << std::endl;
    // Calling RandomChump creates a zombie on the stack.
    //  Notice in the output that its destructor is caalled inmediately after it announces itself,
    //  because its goes out of scope when the function ends.
    randomChump("Stacky");

    std::cout << "\n--- Testing Heap Allocation ---" << std::endl;
    // Calling newZombie creates a zombie on the heap.
    // We can use it outside of the function that creaated it.
    Zombie *heapZombie = newZombie("Heapy");

    heapZombie->announce();

    // Because itś on the heap, it won´t be destroyed automatically.
    // We MUST call delete to trigger the destructor and free the memory.
    std::cout << "Deleting heap zombie manually:" << std::endl;
    delete heapZombie;

    return 0;
}