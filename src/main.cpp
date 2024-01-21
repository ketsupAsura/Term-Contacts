#include "file_io.h"
#include "contact_manager.h"

int main()
{
    system("color 04");
    const std::string filename = "../data/contacts.csv";
    std::vector<Contact> contactList = FileIO::loadContacts(filename);
    ContactManager* contactManager = new ContactManager(contactList);

    std::string command; // container for the user selected option
    while (true)
    {
        system("cls");
        command = UserInterface::mainMenuInput();

        if (command == "M") { contactManager->manageContactMenu(); } 
        else if (command == "V") { contactManager->viewContactMenu(); } 
        else if (command == "S") { contactManager->searchContactMenu(); } 
        else if (command == "E") { break; } 
        else {
            std::cout << "\n\nInvalid Command\n";
            system("pause");
        }
    }
    
    // save the changes 
    FileIO::saveContacts(filename, contactManager->getContactList());

    return 0;
}
