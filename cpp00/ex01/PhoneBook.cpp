#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook(void) {
  _index = 0;
  _total = 0;
}

PhoneBook::~PhoneBook(void) {}

std::string PhoneBook::_formatColumn(std::string str) const {
  if (str.length() > 10) {
    return (str.substr(0, 9) + ".");
  }
  return (str);
}

static std::string getInput(std::string prompt) {
  std::string input = "";

  while (true) {
    std::cout << prompt;
    if (!std::getline(std::cin, input)) {
      std::cout << std::endl;
      return ("");
    }
    if (!input.empty()) {
      break;
    }
    std::cout << "Error: Field cannot be empty." << std::endl;
  }
  return (input);
}

void PhoneBook::addContact(void) {
  std::string first, last, nick, phone, secret;

  first = getInput("First name: ");
  if (first.empty() && std::cin.eof())
    return;
  last = getInput("Last name: ");
  if (last.empty() && std::cin.eof())
    return;
  nick = getInput("Nickname: ");
  if (nick.empty() && std::cin.eof())
    return;
  phone = getInput("Phone number: ");
  if (phone.empty() && std::cin.eof())
    return;
  secret = getInput("Darkest secret: ");
  if (secret.empty() && std::cin.eof())
    return;
  int contactIndex;

  if (_index < 8) {
    contactIndex = _index;
    _index++;
    if (_total < 8) {
      _total++;
    }
  } else {
    contactIndex = 0;
  }

  _contacts[contactIndex].setFirstName(first);
  _contacts[contactIndex].setLastName(last);
  _contacts[contactIndex].setNickname(nick);
  _contacts[contactIndex].setPhoneNumber(phone);
  _contacts[contactIndex].setDarkestSecret(secret);

  std::cout << "Contact added successfully." << std::endl;
}

void PhoneBook::searchContact(void) const {
  if (_total == 0) {
    std::cout << "PhoneBook is empty." << std::endl;
    return;
  }

  // Print header table
  std::cout << "|" << std::setw(10) << std::right << "Index"
            << "|" << std::setw(10) << std::right << "First Name"
            << "|" << std::setw(10) << std::right << "Last Name"
            << "|" << std::setw(10) << std::right << "Nickname"
            << "|" << std::endl;
  std::cout << "---------------------------------------------+" << std::endl;

  for (int i = 0; i < _total; i++) {
    std::cout << "|" << std::setw(10) << std::right << i << "|" << std::setw(10)
              << std::right << _formatColumn(_contacts[i].getFirstName()) << "|"
              << std::setw(10) << std::right
              << _formatColumn(_contacts[i].getLastName()) << "|"
              << std::setw(10) << std::right
              << _formatColumn(_contacts[i].getNickname()) << "|" << std::endl;
  }

  std::cout << "Enter index to display: ";
  std::string input;
  if (!std::getline(std::cin, input)) {
    std::cout << std::endl;
    return;
  }

  if (input.empty()) {
    std::cout << "Error: Invalid index." << std::endl;
    return;
  }

  // Verify if the enter is a digit from 0 to 7 and its in the correct range
  if (input.length() == 1 && input[0] >= '0' && input[0] <= '7') {
    int idx = input[0] - '0';
    if (idx < _total) {
      std::cout << "First name: " << _contacts[idx].getFirstName() << std::endl;
      std::cout << "Last name: " << _contacts[idx].getLastName() << std::endl;
      std::cout << "Nickname: " << _contacts[idx].getNickname() << std::endl;
      std::cout << "Phone number: " << _contacts[idx].getPhoneNumber()
                << std::endl;
      std::cout << "Darkest secret: " << _contacts[idx].getDarkestSecret()
                << std::endl;
    } else {
      std::cout << "Error: Index out of range." << std::endl;
    }
  } else {
    std::cout << "Error: Invalid index." << std::endl;
  }
}
