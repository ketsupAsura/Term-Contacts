// ketsup@asura
#include "contact.h"


Contact::Contact(std::string name_, std::string phone_number_, std::string email_)
: name(name_), phone_number(phone_number_), email(email_) {}

// default constructor
Contact::Contact() {}

const std::string& Contact::getName() const { 
    return name; 
}

const std::string& Contact::getPhonenumber() const { 
    return phone_number;
}

const std::string& Contact::getEmail() const { 
    return email;
}
