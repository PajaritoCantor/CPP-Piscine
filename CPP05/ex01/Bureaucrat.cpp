/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:40:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/10/19 14:40:00 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Default Constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
}

// Parameterized Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
}

// Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other._grade;
        // _name is const, so it cannot be reassigned
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
}

// Getters
const std::string& Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

// Member functions to modify grade
void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

// Sign Form function
void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->_name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! (Highest allowed is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! (Lowest allowed is 150)";
}

// Stream Insertion Operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
