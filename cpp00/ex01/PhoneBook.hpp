#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
  Contact _contacts[8];
  int _index;
  int _total;

  // Helper method to format columns in SEARCH
  std::string _formatColumn(std::string str) const;

public:
  PhoneBook(void);
  ~PhoneBook(void);

  void addContact(void);
  void searchContact(void) const;
};

#endif
