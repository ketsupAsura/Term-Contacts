// ketsup@asura
#include <iostream>
#include "Contact.h"


Contact::Contact(std::string name_, std::string phone_number_, std::string email_)
: name(name_), phone_number(phone_number_), email(email_) {}

// default constructor
Contact::Contact() {}

std::string Contact::getName() const { 
    return name; 
}

std::string Contact::getPhoneNumber() const { 
    return phone_number;
}

std::string Contact::getEmail() const { 
    return email;
}
