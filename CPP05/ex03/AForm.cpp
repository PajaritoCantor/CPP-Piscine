/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:40:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/10/19 14:40:00 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {
}

// Parameterized Constructor
AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

// Copy Constructor
AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _signGrade(other._signGrade),
      _execGrade(other._execGrade) {
}

// Assignment Operator
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

// Virtual Destructor
AForm::~AForm() {
}

// Getters
const std::string& AForm::getName() const {
    return this->_name;
}

bool AForm::getIsSigned() const {
    return this->_isSigned;
}

int AForm::getSignGrade() const {
    return this->_signGrade;
}

int AForm::getExecGrade() const {
    return this->_execGrade;
}

// beSigned function
void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_signGrade)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

// execute function
void AForm::execute(Bureaucrat const & executor) const {
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_execGrade)
        throw AForm::GradeTooLowException();
    this->executeAction();
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "form is not signed yet!";
}

// Stream Insertion Operator
std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm " << f.getName() << " [signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << f.getSignGrade() << ", exec grade: " << f.getExecGrade() << "]";
    return os;
}
