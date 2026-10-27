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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

static void printHeader(const std::string& title) {
    std::cout << "\n========================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "========================================" << std::endl;
}

int main() {
    std::srand(std::time(NULL));

    Bureaucrat president("Zaphod", 1);
    Bureaucrat manager("Michael Scott", 40);
    Bureaucrat supervisor("Dwight", 130);
    Bureaucrat intern("Ryan", 150);

    printHeader("TEST 1: Execution of Unsigned Form (Should Fail)");
    {
        ShrubberyCreationForm shrub("garden");
        std::cout << shrub << std::endl;
        president.executeForm(shrub);
    }

    printHeader("TEST 2: Grade Too Low to Execute (Signed, but low executor grade)");
    {
        PresidentialPardonForm pardon("Ford Prefect");
        president.signForm(pardon); // President signs (grade 1 <= 25)
        std::cout << pardon << std::endl;

        std::cout << "Intern attempting to execute PresidentialPardon:" << std::endl;
        intern.executeForm(pardon); // Intern grade 150 > 5 -> fails

        std::cout << "President attempting to execute PresidentialPardon:" << std::endl;
        president.executeForm(pardon); // President grade 1 <= 5 -> succeeds
    }

    printHeader("TEST 3: ShrubberyCreationForm (Sign: 145, Exec: 137)");
    {
        ShrubberyCreationForm shrub("home");
        supervisor.signForm(shrub);
        supervisor.executeForm(shrub);
    }

    printHeader("TEST 4: RobotomyRequestForm (Sign: 72, Exec: 45)");
    {
        RobotomyRequestForm robot("Bender");
        manager.signForm(robot);

        std::cout << "\n--- Running multiple executions to test 50% probability ---" << std::endl;
        for (int i = 1; i <= 4; ++i) {
            std::cout << "\n[Attempt " << i << "]" << std::endl;
            manager.executeForm(robot);
        }
    }

    printHeader("TEST 5: Polymorphism using AForm* pointers");
    {
        AForm* forms[3];
        forms[0] = new ShrubberyCreationForm("park");
        forms[1] = new RobotomyRequestForm("Marvin");
        forms[2] = new PresidentialPardonForm("Arthur Dent");

        for (int i = 0; i < 3; ++i) {
            std::cout << "\nPolymorphic test for: " << forms[i]->getName() << std::endl;
            president.signForm(*forms[i]);
            president.executeForm(*forms[i]);
            delete forms[i];
        }
    }

    printHeader("ALL TESTS COMPLETED");
    return 0;
}
