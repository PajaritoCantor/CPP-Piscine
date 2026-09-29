/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureacrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:05:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/09/24 17:57:54 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Exception Implementations
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high (Maximum is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low (Minimum is 150)";
}