/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:40:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/10/19 14:40:00 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _signGrade;
    const int           _execGrade;

protected:
    virtual void        executeAction() const = 0;

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string& name, int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Getters
    const std::string&  getName() const;
    bool                getIsSigned() const;
    int                 getSignGrade() const;
    int                 getExecGrade() const;

    // Member functions
    void                beSigned(const Bureaucrat& b);
    void                execute(Bureaucrat const & executor) const;

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
