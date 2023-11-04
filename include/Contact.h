#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

class Contact {
private:
    std::string name;
    std::string phone_number;
    std::string email;

    // ContactManager class can access this class private fields
    friend class ContactManager;

public: 
    Contact(std::string name_, std::string phone_number_, std::string email_);

    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
};

#endif
