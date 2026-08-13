#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap
{
public:
    // Forma Canónica Ortodoxa
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    // Sobreescritura de la función attack
    void attack(const std::string &target);

    // Habilidad especial
    void guardGate();
};

#endif