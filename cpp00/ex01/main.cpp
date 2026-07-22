#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av) {
  (void)ac;
  (void)av;
  PhoneBook book;
  std::string cmd;

  std::cout << "========================================" << std::endl;
  std::cout << "        WELCOME TO MY PHONEBOOK         " << std::endl;
  std::cout << "========================================" << std::endl;

  while (true) {
    std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
    if (!std::getline(std::cin, cmd)) {
      std::cout << "\nGoodbye! Contacts are lost forever." << std::endl;
      break;
    }
    if (cmd == "EXIT") {
      std::cout << "Goodbye! Contacts are lost forever." << std::endl;
      break;
    } else if (cmd == "ADD") {
      book.addContact();
    } else if (cmd == "SEARCH") {
      book.searchContact();
    } else {
      if (!cmd.empty()) {
        std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT."
                  << std::endl;
      }
    }
  }
  return (0);
}
