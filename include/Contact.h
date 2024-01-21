// ketsup@asura/matthew
#pragma once

#include <string>

class Contact {
private:
    std::string name;
    std::string phone_number;
    std::string email;

    // ContactManager class can access this class private fields
    friend class ContactManager;

public: 
    Contact(std::string name_, std::string phone_number_, std::string email_);
    Contact();

    const std::string& getName() const;
    const std::string& getPhonenumber() const;
    const std::string& getEmail() const;
};

