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
#include "Intern.hpp"
#include <ctime>

static void printHeader(const std::string& title) {
    std::cout << "\n========================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "========================================" << std::endl;
}

int main() {
    std::srand(std::time(NULL));

    Bureaucrat boss("Zaphod Beeblebrox", 1);
    Intern someRandomIntern;

    printHeader("TEST 1: Subject Example (robotomy request on Bender)");
    {
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            std::cout << *rrf << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
    }

    printHeader("TEST 2: Intern creating ShrubberyCreationForm");
    {
        AForm* scf;
        scf = someRandomIntern.makeForm("shrubbery creation", "palace_garden");
        if (scf) {
            std::cout << *scf << std::endl;
            boss.signForm(*scf);
            boss.executeForm(*scf);
            delete scf;
        }
    }

    printHeader("TEST 3: Intern creating PresidentialPardonForm");
    {
        AForm* ppf;
        ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        if (ppf) {
            std::cout << *ppf << std::endl;
            boss.signForm(*ppf);
            boss.executeForm(*ppf);
            delete ppf;
        }
    }

    printHeader("TEST 4: Intern receiving Non-Existent Form Name");
    {
        AForm* badForm;
        badForm = someRandomIntern.makeForm("coffee making request", "Boss");
        if (badForm == NULL) {
            std::cout << "Correct: Pointer is NULL as expected for invalid form name." << std::endl;
        } else {
            delete badForm;
        }
    }

    printHeader("TEST 5: Canonical form of Intern (Copy & Assign)");
    {
        Intern intern1;
        Intern intern2(intern1);
        Intern intern3;
        intern3 = intern2;

        AForm* testForm = intern3.makeForm("robotomy request", "Wall-E");
        if (testForm) {
            boss.signForm(*testForm);
            boss.executeForm(*testForm);
            delete testForm;
        }
    }

    printHeader("ALL TESTS COMPLETED");
    return 0;
}
