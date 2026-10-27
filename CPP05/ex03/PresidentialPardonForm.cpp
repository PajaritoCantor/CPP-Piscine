/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:40:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/10/19 14:40:00 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("default_target") {
}

// Parameterized Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {
}

// Assignment Operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
}

const std::string& PresidentialPardonForm::getTarget() const {
    return this->_target;
}

// executeAction implementation: pardon by Zaphod Beeblebrox
void PresidentialPardonForm::executeAction() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
