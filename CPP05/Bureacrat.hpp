/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureacrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:56:12 by jurodrig          #+#    #+#             */
/*   Updated: 2026/09/24 16:01:59 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT__HPP
# define BUREAUCRAT__HPP

# include <iostream>
# include <string>
# include <exception>

class   Bureacrat {
    private:
        const std::string _name;
        int _grade;

    public:
    Bureacrat();
    Bureacrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureacrat& other);
    ~Bureacrat();


    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Method Exception Classes
    void    incrementGrade();
    void    decrementGrade();

    // Nested Exception Classes
    class GradeTooHighException : public std::exception {
        public::
            virtual const char* what() const throw();
    }

    class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureacrat& b);

#endif