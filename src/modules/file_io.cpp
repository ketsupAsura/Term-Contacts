#include "file_io.h"

// reads the contacts from the data file
std::vector<Contact> FileIO::loadContacts(const std::string& filename) {
    std::vector<Contact> contacts;
    std::ifstream fhand(filename);

    // check if the file to be read can be opened
    if (!fhand.is_open())
    {
        throw std::runtime_error("Cannot open file " + filename + "; no such file in directory");
    }

    std::string line; // container for every line in the csv file
    std::string name, phone_number, email; // container for every fields of the contact obj
    while (std::getline(fhand, line)) {
        std::istringstream contact(line); // break each lines into tokens

        std::getline(contact, name, ',');           // the first token is the name
        std::getline(contact, phone_number, ',');   // the second token is the phone number
        std::getline(contact, email);               // the third token is the email
        
        // put the contact into the list
        contacts.emplace_back(name, phone_number, email);
    }

    fhand.close(); // close the file
    
    return contacts;
}

// overwrite all the old contents of the file
// and put the new contacts in the data file
void FileIO::saveContacts(const std::string& filename, const std::vector<Contact>& contacts) {
    std::ofstream fhand(filename);

    // check if the file to be write can be opened
    if (!fhand.is_open())
    {
        throw std::runtime_error("Cannot write to file " + filename + "; no such file in directory");
    }

    std::string line;
    for (const auto& contact : contacts) {
        line = contact.getName() + "," + contact.getPhonenumber() + "," + contact.getEmail() + "\n";
        fhand << line;
    }

    fhand.close(); // close the file
}

