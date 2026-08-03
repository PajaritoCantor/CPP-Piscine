/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:22:20 by jurodrig          #+#    #+#             */
/*   Updated: 2026/08/03 18:22:46 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "--- TEST: DEBUG ---" << std::endl;
    harl.complain("DEBUG");

    std::cout << "--- TEST: INFO ---" << std::endl;
    harl.complain("INFO");

    std::cout << "--- TEST: WARNING ---" << std::endl;
    harl.complain("WARNING");

    std::cout << "--- TEST: ERROR ---" << std::endl;
    harl.complain("ERROR");

    std::cout << "--- TEST: UNKNOWN LEVEL ---" << std::endl;
    harl.complain("HOLA");

    return 0;
}