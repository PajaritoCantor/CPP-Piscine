/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:40:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/10/19 14:40:00 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Default Constructor
Intern::Intern() {
}

// Copy Constructor
Intern::Intern(const Intern& other) {
    (void)other;
}

// Assignment Operator
Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

// Destructor
Intern::~Intern() {
}

// Creator Helpers
AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// makeForm: Dispatch table using function pointers (avoiding excessive if/else if/else)
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    typedef AForm* (*FormCreator)(const std::string&);

    struct FormEntry {
        const char* name;
        FormCreator creator;
    };

    const FormEntry knownForms[] = {
        {"shrubbery creation", &Intern::createShrubbery},
        {"robotomy request", &Intern::createRobotomy},
        {"presidential pardon", &Intern::createPresidential}
    };

    const int formCount = 3;

    for (int i = 0; i < formCount; ++i) {
        if (formName == knownForms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return knownForms[i].creator(target);
        }
    }

    std::cout << "Intern could not create form: \"" << formName << "\" does not exist!" << std::endl;
    return NULL;
}
