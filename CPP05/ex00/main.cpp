/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:40:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/10/19 14:40:00 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void printHeader(const std::string& title) {
    std::cout << "\n========================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "========================================" << std::endl;
}

int main() {
    printHeader("TEST 1: Valid Instantiations & operator<<");
    try {
        Bureaucrat b1("Hermes Conrad", 1);
        Bureaucrat b2("Dwight Schrute", 150);
        Bureaucrat b3("Default Bureaucrat", 75);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    printHeader("TEST 2: Invalid Instantiation (Grade Too High: 0)");
    try {
        Bureaucrat bInvalid("Overachiever", 0);
        std::cout << bInvalid << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    printHeader("TEST 3: Invalid Instantiation (Grade Too Low: 151)");
    try {
        Bureaucrat bInvalid("Slacker", 151);
        std::cout << bInvalid << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    printHeader("TEST 4: Incrementing Grade (Normal and Limit)");
    try {
        Bureaucrat b("Alice", 3);
        std::cout << "Initial: " << b << std::endl;

        b.incrementGrade();
        std::cout << "After 1st increment (3 -> 2): " << b << std::endl;

        b.incrementGrade();
        std::cout << "After 2nd increment (2 -> 1): " << b << std::endl;

        std::cout << "Attempting to increment grade 1..." << std::endl;
        b.incrementGrade();
        std::cout << "This line should never be printed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    printHeader("TEST 5: Decrementing Grade (Normal and Limit)");
    try {
        Bureaucrat b("Bob", 149);
        std::cout << "Initial: " << b << std::endl;

        b.decrementGrade();
        std::cout << "After 1st decrement (149 -> 150): " << b << std::endl;

        std::cout << "Attempting to decrement grade 150..." << std::endl;
        b.decrementGrade();
        std::cout << "This line should never be printed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    printHeader("TEST 6: Orthodox Canonical Form (Copy & Assignment)");
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        Bureaucrat assigned("Assigned", 100);

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
        std::cout << "Assigned before: " << assigned << std::endl;

        assigned = original;
        std::cout << "Assigned after:  " << assigned << " (grade copied from original)" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    printHeader("ALL TESTS COMPLETED");
    return 0;
}
