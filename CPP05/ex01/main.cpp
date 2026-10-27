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
#include "Form.hpp"

static void printHeader(const std::string& title) {
    std::cout << "\n========================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "========================================" << std::endl;
}

int main() {
    printHeader("TEST 1: Valid Forms & operator<<");
    try {
        Form f1("Tax Exemption", 50, 25);
        Form f2("Building Permit", 100, 75);
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    printHeader("TEST 2: Invalid Form Creation (Grades out of bounds)");
    try {
        std::cout << "Creating Form with sign grade 0:" << std::endl;
        Form f("InvalidHighSign", 0, 50);
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Creating Form with exec grade 0:" << std::endl;
        Form f("InvalidHighExec", 50, 0);
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Creating Form with sign grade 151:" << std::endl;
        Form f("InvalidLowSign", 151, 50);
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Creating Form with exec grade 151:" << std::endl;
        Form f("InvalidLowExec", 50, 151);
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    printHeader("TEST 3: Successful Signing (Bureaucrat has sufficient grade)");
    try {
        Bureaucrat boss("Chief Director", 10);
        Form f("Budget Approval", 20, 10);

        std::cout << "Before signing: " << f << std::endl;
        boss.signForm(f);
        std::cout << "After signing:  " << f << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    printHeader("TEST 4: Failed Signing (Bureaucrat grade too low)");
    try {
        Bureaucrat intern("Coffee Intern", 140);
        Form topSecret("Nuclear Launch Code", 1, 1);

        std::cout << intern << std::endl;
        std::cout << topSecret << std::endl;

        intern.signForm(topSecret);
        std::cout << "Form status: " << topSecret << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    printHeader("TEST 5: Direct beSigned() call exception check");
    try {
        Bureaucrat b("Average Joe", 80);
        Form f("Secret Project", 50, 30);

        std::cout << "Directly calling f.beSigned(b)..." << std::endl;
        f.beSigned(b);
    } catch (const std::exception& e) {
        std::cout << "Caught direct exception: " << e.what() << std::endl;
    }

    printHeader("TEST 6: Form Orthodox Canonical Form (Copy & Assign)");
    try {
        Form f1("OriginalForm", 42, 21);
        Bureaucrat b("Officer", 30);
        b.signForm(f1);

        Form f2(f1);
        Form f3("AnotherForm", 100, 100);
        f3 = f1;

        std::cout << "Original: " << f1 << std::endl;
        std::cout << "Copy:     " << f2 << std::endl;
        std::cout << "Assigned: " << f3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    printHeader("ALL TESTS COMPLETED");
    return 0;
}
