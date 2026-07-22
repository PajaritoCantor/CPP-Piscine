#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

void Contact::setFirstName(std::string str) { _firstName = str; }

void Contact::setLastName(std::string str) { _lastName = str; }

void Contact::setNickname(std::string str) { _nickname = str; }

void Contact::setPhoneNumber(std::string str) { _phoneNumber = str; }

void Contact::setDarkestSecret(std::string str) { _darkestSecret = str; }

std::string Contact::getFirstName(void) const { return (_firstName); }

std::string Contact::getLastName(void) const { return (_lastName); }

std::string Contact::getNickname(void) const { return (_nickname); }

std::string Contact::getPhoneNumber(void) const { return (_phoneNumber); }

std::string Contact::getDarkestSecret(void) const { return (_darkestSecret); }
