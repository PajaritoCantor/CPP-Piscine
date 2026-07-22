#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickname;
  std::string _phoneNumber;
  std::string _darkestSecret;

public:
  Contact(void);
  ~Contact(void);

  // Setters
  void setFirstName(std::string str);
  void setLastName(std::string str);
  void setNickname(std::string str);
  void setPhoneNumber(std::string str);
  void setDarkestSecret(std::string str);

  // Getters
  std::string getFirstName(void) const;
  std::string getLastName(void) const;
  std::string getNickname(void) const;
  std::string getPhoneNumber(void) const;
  std::string getDarkestSecret(void) const;
};

#endif
