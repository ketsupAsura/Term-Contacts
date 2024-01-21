// ketsup@asura/matthew
#include "file_io.h"
#include "contact_manager.h"

int main()
{
    system("color 02"); // set the terminal font color to green
    const std::string filename = "../data/contacts.csv"; // database file
    std::vector<Contact> contactList = FileIO::loadContacts(filename); // load the data in the file
    ContactManager* contactManager = new ContactManager(contactList); // instance of the ContactManager class

    std::string command; // container for the user selected option
    while (true)
    {
        system("cls");
        command = UserInterface::mainMenuInput(); // displays the main options of the program

        // sub menus
        if (command == "M") { contactManager->manageContactMenu(); } 
        else if (command == "V") { contactManager->viewContactMenu(); } 
        else if (command == "S") { contactManager->searchContactMenu(); } 
        else if (command == "E") { break; } 
        else {
            UserInterface::warningMessage();
        }
    }
    
    // save the changes to the file 
    FileIO::saveContacts(filename, contactManager->getContactList());

    return 0;
}
