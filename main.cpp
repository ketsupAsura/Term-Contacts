#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"

enum ComparisonResult { 
    LESS,     // smaller value 
    GREATER,  // larger value
    EQUAL     // equal value
};

// used for sorting
// the following 3 comparator functions is used to compare the Contact objects
// in the contactList vector based on the fileter the user selected to view the contactList
bool compareContactByName(const Contact& contact1, const Contact& contact2) {
    return contact1.getName() < contact2.getName();
}

bool compareContactByPhoneNumber(const Contact& contact1, const Contact& contact2) {
    return contact1.getPhoneNumber() < contact2.getPhoneNumber();
}

bool compareContactByEmail(const Contact& contact1, const Contact& contact2) {
    return contact1.getEmail() < contact2.getEmail();
}

// used for searching
// the following 3 comparator functions is used to compare(if equal) the Contact object to the search of the user
// in the contactList vector based on what filter the user selected to search in the contactList
ComparisonResult searchContactByName(const Contact& contact, std::string& nameSearched) {
    if (contact.getName() < nameSearched) { return LESS; }
    else if (contact.getName() > nameSearched) { return GREATER; }
    else return EQUAL;
}

ComparisonResult searchContactByPhoneNumber(const Contact& contact, std::string& phoneNumberSearched) {
    if (contact.getPhoneNumber() < phoneNumberSearched) { return LESS; }
    else if (contact.getPhoneNumber() > phoneNumberSearched) { return GREATER; }
    else return EQUAL;
}

ComparisonResult searchContactByEmail(const Contact& contact, std::string& emailSearched) {
    if (contact.getEmail() < emailSearched) { return LESS; }
    else if (contact.getEmail() > emailSearched) { return GREATER; }
    else return EQUAL;
}


class ContactManager {
private:
    std::vector<Contact> contactList;
public:
    // In mergeSort I passed the vector since it needs to divide the vector 
    // into left and right temporary vectors (container for left and right vector),
    // during the recurssion, until there is only one element in the temporary vector, 
    // then the functions will be called in the stack to complete the call, 
    // this is where the merging and sorting of the temporary vectors back the original vector(contactList) will take place
    void mergeSort(std::vector<Contact>& contactList_, bool (*comparatorFunction)(const Contact& contac1, const Contact& contact2));
    void merge(std::vector<Contact>& leftArray, std::vector<Contact>& rightArray, std::vector<Contact>& contactList_, bool (*comparatorFunction)(const Contact& contact1, const Contact& contact2)); // helper method for mergeSort
    
    // In quick sort I didn't pass the contactList since I don't need to create temporary vector containers,
    // since sorting happens in the original vector and the vector is a field of the class meaning the methods of the class have acces to it, 
    // just that it is divided by a pivot(the pivot is the last element in this quicksort), which will then be placed at the part of the vector, 
    // wherein the left side of the pivot are elements that is less than the pivot and 
    // on the right side of the pivot are elements that is greater than the pivot (this is done by the helper function named partition),
    // more details....
    void quickSort(int start, int end, bool (*comparatorFunction)(const Contact& contact1, const Contact& contact2));
    int partition(int start, int end, bool (*comparatorFunction)(const Contact& contact1, const Contact& contact2));

    void binarySearch(std::string& contactDetail, ComparisonResult (*searchComparatorFunction)(const Contact& contact, std::string& contactDetail));

    void menu();
    void manageContactMenu();
    void addContact();
    void editContact();
    void deleteContact();
    void viewContactMenu();
    void printContactList(std::string& sortBy);
    void searchContactMenu();
    void searchContactList(std::string& filter);
};


void ContactManager::merge(std::vector<Contact>& leftArray, std::vector<Contact>& rightArray, std::vector<Contact>& contactList_, bool (*comparatorFunction)(const Contact& contact1, const Contact& contact2)) {
    int leftSize = contactList_.size() / 2;
    int rightSize = contactList_.size() - leftSize;

    // i for the original array, l for the leftArray, r for the rightArray
    int i = 0, l = 0, r = 0; // indices
    

    while (l < leftSize && r < rightSize) {
        if (comparatorFunction(leftArray[l], rightArray[r])) {
            contactList_[i] = leftArray[l];
            i++;
            l++;
        }
        else {
            contactList_[i] =  rightArray[r];
            i++;
            r++;
        }
    }

    while (l < leftSize) {
        contactList_[i] = leftArray[l];
        i++;
        l++;
    }

    while (r < rightSize) {
        contactList_[i] = rightArray[r];
        i++;
        r++;
    }
}

void ContactManager::mergeSort(std::vector<Contact>& contactList_, bool (*comparatorFunction)(const Contact& contact1, const Contact& contact2)) {
    int size = contactList_.size();
    if (size <= 1) return; // base case
    
    int middle = size / 2;
    std::vector<Contact> leftArray;
    std::vector<Contact> rightArray;

    int i = 0; // left array
    int j = 0; // right array
    
    for (; i < size; i++) {
        if (i < middle) {
            leftArray.push_back(contactList_[i]);
        } else {
            rightArray.push_back(contactList_[i]);
            j++;
        }
    }

    mergeSort(leftArray, comparatorFunction);
    mergeSort(rightArray, comparatorFunction);
    merge(leftArray, rightArray, contactList_, comparatorFunction);

}

int ContactManager::partition(int start, int end, bool (*comparatorFunction)(const Contact& contact1, const Contact& contact2)) {

    // the pivot well be the last element of the vector
    Contact pivot = contactList[end];

    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {

        if (comparatorFunction(contactList[j], pivot)) {
            i++;
             
            Contact temp = contactList[i];
            contactList[i] = contactList[j];
            contactList[j] = temp;
        }
    }

    i++;

    Contact temp = contactList[i];
    contactList[i] = contactList[end];
    contactList[end] = temp;
    return i;
}

void ContactManager::quickSort(int start, int end, bool (*comparatorFunction)(const Contact& contact1, const Contact& contact2)) {
     
    if (end <= start) { return; } // base case
    
    int pivot = partition(start, end, comparatorFunction);

    // left partition
    quickSort(start, pivot - 1, comparatorFunction);

    // right partition
    quickSort(pivot + 1, end, comparatorFunction);

}


void ContactManager::binarySearch(std::string& contactDetail, ComparisonResult (*searchComparatorFunction)(const Contact& contact, std::string& contactDetail)) {
    int low = 0;
    int high = contactList.size() - 1;

    while (low <= high) {
        int middle = low + (high - low) / 2;
        Contact contact = contactList[middle];

        ComparisonResult comparisonResult = searchComparatorFunction(contact, contactDetail);

        if (comparisonResult == LESS) { low = middle + 1; } 
        else if ( comparisonResult == GREATER) { high = middle - 1; } 
        else if (comparisonResult = EQUAL) {
            std::cout << "Contact Found!\n\n";
            std::cout << "Name: " << contact.name << "\n";
            std::cout << "Phone Number: " << contact.phone_number << "\n";
            std::cout << "Email: " << contact.email << "\n\n";
            return; // target found
        }

        /*
        if (value < target) { low = middle + 1; }
        else if (value > target) { high = middle - 1; }
        else return middle; // target is found
        */
    }
    std::cout << "Contact Not Found!\n\n"; 

    /*
    std::string searchAnotherContact;
    while (true) {
        std::cout << "Do you want to search another contact[y/n]: ";
        std::getline(std::cin, searchAnotherContact);

        if (searchAnotherContact == "y") {

        }
    }*/

}

void ContactManager::menu() {
    std::string command;

    while (true) {
        system("cls");

        std::cout << "Contact Manager System Menu\n";
        std::cout << "[M] Manage Contact\n";
        std::cout << "[V] View Contact\n";
        std::cout << "[S] Search Contact\n";
        std::cout << "[E] Exit\n"; 
        std::cout << "Command: ";
        std::getline(std::cin, command);

        if (command == "M") {
            manageContactMenu();
        } 
        else if (command == "V") {
            viewContactMenu();
        } 
        else if (command == "S") {
            searchContactMenu();
        } 
        else if (command == "E") {
            return;
        } 
        else {
            std::cout << "\n\nInvalid Command\n";
            system("pause");
        }
    }

    /*
    switch (command) {
        case "M":
            manageContactMenu();
            break;
        case "V":
            viewContactMenu();
            break;
        case "S":
            searchContact();
            break;
        case "E": return;
        default: std::cout << "Invalid Command!\n";
    }
    */
}

void ContactManager::manageContactMenu() {
    std::string command;

    while (true) {
        system("cls");

        std::cout << "Manage Contacts\n";
        std::cout << "[A] Add Contact\n";
        std::cout << "[E] Edit Contact\n";
        std::cout << "[D] Delete Contact\n";
        std::cout << "[B] Back\n";
        std::cout << "Command: ";
        std::getline(std::cin, command);

        if (command == "A") {
            addContact();
        } 
        else if (command == "E") {
            editContact();
        } 
        else if (command == "D") {
            deleteContact();
        } 
        else if (command == "B") {
            return;
        } 
        else {
            std::cout << "\n\nInvalid Command\n";
            system("pause");
        }
    }

    /*
    switch (command) {
        case "A": addContact(); break;
        case "E": editContact(); break;
        case "D": deleteContact(); break;
        case "B": return;
        default: std::cout << "Invalid Command!\n";
    }
    */
}

void ContactManager::addContact() {
    std::string addMoreContact;
    std::string name;
    std::string phone_number;
    std::string email;

    while (true) {
        system("cls");

        std::cout << "Add Contact\n";
        
        // get contact name
        std::cout << "Enter contact name: "; 
        std::getline(std::cin, name);

        // get contact phone number
        std::cout << "Enter contact phone number: ";
        std::getline(std::cin, phone_number);
        
        // get contact email
        std::cout << "Enter contact email: ";
        std::getline(std::cin, email);

        // create a contact obj
        Contact contact = Contact(name, phone_number, email);

        // add the contact obj to the contactList
        contactList.push_back(contact);

        // checks if the user wants to add more contacts
        while (true) {
            std::cout << "\n\nDo you want to add more contact[y/n]: ";
            std::getline(std::cin, addMoreContact);

            if (addMoreContact == "y") { break; }
            else if (addMoreContact == "n") { return; }
        }
    }
}

void ContactManager::editContact() {
    std::string contactName;
    std::string editAnotherContact;
    bool contactEdited;

    std::string name;
    std::string phone_number;
    std::string email;
    while (true) {
        system("cls");

        std::cout << "Edit Contact\n";

        // get the contact name to be edited
        std::cout << "Enter contact name to edit: ";
        std::getline(std::cin, contactName);

        // find the contact the user wants to edit in the contactList
        for (int i = 0; i < contactList.size(); i++) {
            if (contactList[i].name == contactName) {

                // edit contact name
                std::cout << "Enter new contact name: "; 
                std::getline(std::cin, name);
                contactList[i].name = name;

                // edit contact phone number
                std::cout << "Enter new contact phone number: ";
                std::getline(std::cin, phone_number);
                contactList[i].phone_number = phone_number;
                
                // edit contact email
                std::cout << "Enter new contact email: ";
                std::getline(std::cin, email);
                contactList[i].email = email;

                contactEdited = true;
                break; // exit the loop after the contact is edited
            }
        }

        if (contactEdited) {
            std::cout << "Contact Edited Successfully!\n";
            contactEdited = false;
        } else {
            std::cout << "Contact Not Found!\n";
        }

        // ask the user if they want to edit another contact
        while (true) {
            std::cout << "\n\nDo you want to edit another contact[y/n]: ";
            std::getline(std::cin, editAnotherContact);

            if (editAnotherContact == "y") { break; }
            else if (editAnotherContact == "n") { return; }
        }
    }
}

void ContactManager::deleteContact() {
    std::string contactName;
    std::string deleteAnotherContact;
    bool contactDeleted = false;
    while (true) {
        system("cls");

        std::cout << "Delete Contact\n";

        // get the contact name to be deleted
        std::cout << "Enter contact name to delete: ";
        std::getline(std::cin, contactName);

        // find the contact the user wants to delete in the contactList
        for (int i = 0; i < contactList.size(); i++) {
            if (contactList[i].name == contactName) {

                // delete the contact
                contactList.erase(contactList.begin() + i);
                contactDeleted = true;
                break; // exit the loop after the contact is edited
            }
        }

        if (contactDeleted) {
            std::cout << "Contact Deleted Successfully!\n";
            contactDeleted = false;
        } else {
            std::cout << "Contact Not Found!\n";
        }

        // ask the user if they want to edit another contact
        while (true) {
            std::cout << "\n\nDo you want to delete another contact[y/n]: ";
            std::getline(std::cin, deleteAnotherContact);

            if (deleteAnotherContact == "y") { break; }
            else if (deleteAnotherContact == "n") { return; }
        }
    }
}

void ContactManager::viewContactMenu() {
    std::string command;
    while (true) {
        system("cls");

        std::cout << "View Contacts\n";
        std::cout << "[N] View By Name\n";
        std::cout << "[P] View By Phone Number\n";
        std::cout << "[E] View By Email\n";
        std::cout << "[B] Back\n";
        std::cout << "Command: ";
        std::getline(std::cin, command);

        if (command == "N" || command == "P" || command == "E") {
            printContactList(command);
        } 
        else if (command == "B") {
            return;
        } 
        else {
            std::cout << "\n\nInvalid Command\n";
            system("pause");
        }
    }

    /*
    switch (command) {
        case "N": printContactList(command); break;
        case "P": printContactList(command); break;
        case "E": printContactList(command); break;
        case "B": return;
    }
    */
}

// prints the contact based on the filter choosen by the user
void ContactManager::printContactList(std::string& filter) {
    // function pointer will point to a comapartor function
    // based on how the user wants to view the contactList
    bool (*comparatorFunction) (const Contact& contact1, const Contact& contact2);

    if (filter == "N") { comparatorFunction = compareContactByName; }
    else if (filter == "P") { comparatorFunction = compareContactByPhoneNumber; }
    else if (filter == "E") { comparatorFunction = compareContactByEmail; }

    //quickSort(0, contactList.size() - 1, comparatorFunction);
    mergeSort(contactList, comparatorFunction);

    system("cls");
    std::cout << "================ CONTACT LIST ==================\n\n";
    for (int i = 0; i < contactList.size(); i++) {
        std::cout << "Name: " << contactList[i].name << "\n";
        std::cout << "Phone Number: " << contactList[i].phone_number << "\n";
        std::cout << "Email: " << contactList[i].email << "\n";
        std::cout << "================================================\n\n";
    }
    system("pause");
}

// menu for searching contacts
void ContactManager::searchContactMenu() {
    std::string command;

    while (true) {
        system("cls");

        std::cout << "Search Contact \n";
        std::cout << "[N] Search By Name\n";
        std::cout << "[P] Search By Phone Number\n";
        std::cout << "[E] Search By Email\n";
        std::cout << "[B] Back\n";
        std::cout << "Command: ";
        std::getline(std::cin, command);

        if (command == "N" || command == "P" || command == "E") {
            searchContactList(command);
        } 
        else if (command == "B") {
            return;
        } 
        else {
            std::cout << "\n\nInvalid Command\n";
            system("pause");
        }
    }
}


void ContactManager::searchContactList(std::string& filter) {
    // function pointer will point to a comapartor function
    // based on what filter the user selected to search the contactList
   
    // used for sorting
    bool (*sortComparatorFunction)(const Contact& contact1, const Contact& contact2);

    // used for searching 
    ComparisonResult (*searchComparatorFunction) (const Contact& contact, std::string& contactDetail);


    std::string searchPrompt;
    if (filter == "N") { 
        searchPrompt = "\n\nEnter Contact Name: ";
        sortComparatorFunction = compareContactByName;
        searchComparatorFunction = searchContactByName; 
    }
    else if (filter == "P") { 
        searchPrompt = "\n\nEnter Contact Phone Number: ";
        sortComparatorFunction = compareContactByPhoneNumber;
        searchComparatorFunction = searchContactByPhoneNumber;
    }
    else if (filter == "E") { 
        searchPrompt = "\n\nEnter Contact Email: ";
        sortComparatorFunction = compareContactByEmail;
        searchComparatorFunction = searchContactByEmail;
    }

    quickSort(0, contactList.size() - 1, sortComparatorFunction);

    std::string contactDetail;
    std::cout << searchPrompt;
    std::getline(std::cin, contactDetail);

    system("cls");

    // search contact
    binarySearch(contactDetail, searchComparatorFunction);

    system("pause");

}

int main() {
    ContactManager contactManager = ContactManager();
    contactManager.menu();
    return 0;
}