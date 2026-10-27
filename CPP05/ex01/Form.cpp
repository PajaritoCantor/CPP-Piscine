/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:40:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/10/19 14:40:00 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {
}

// Parameterized Constructor
Form::Form(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _signGrade(other._signGrade),
      _execGrade(other._execGrade) {
}

// Assignment Operator
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
        // _name, _signGrade, and _execGrade are const and cannot be assigned
    }
    return *this;
}

// Destructor
Form::~Form() {
}

// Getters
const std::string& Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

int Form::getSignGrade() const {
    return this->_signGrade;
}

int Form::getExecGrade() const {
    return this->_execGrade;
}

// beSigned function
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_signGrade)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

// Stream Insertion Operator
std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName() << " [signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << f.getSignGrade() << ", exec grade: " << f.getExecGrade() << "]";
    return os;
}
