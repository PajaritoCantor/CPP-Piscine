/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:40:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/10/19 14:40:00 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default_target") {
}

// Parameterized Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {
}

// Assignment Operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
}

const std::string& RobotomyRequestForm::getTarget() const {
    return this->_target;
}

// executeAction implementation: drilling noises and 50% success robotomy
void RobotomyRequestForm::executeAction() const {
    std::cout << "* BZZZZZZT! DRILLING NOISES... VRRRRRRR! *" << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy of " << this->_target << " failed!" << std::endl;
    }
}
