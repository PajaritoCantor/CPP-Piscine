/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:40:00 by jurodrig          #+#    #+#             */
/*   Updated: 2026/10/19 14:40:00 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default_target") {
}

// Parameterized Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {
}

// Assignment Operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
}

const std::string& ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

// executeAction implementation: creates <target>_shrubbery and draws ASCII trees
void ShrubberyCreationForm::executeAction() const {
    std::string filename = this->_target + "_shrubbery";
    std::ofstream outfile(filename.c_str());

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open output file " << filename << std::endl;
        return;
    }

    outfile << "               ,@@@@@@@,\n"
            << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
            << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
            << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
            << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
            << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
            << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
            << "       |o|        | |         | |\n"
            << "       |.|        | |         | |\n"
            << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

    outfile.close();
}
