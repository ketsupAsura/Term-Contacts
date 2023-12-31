// ketsup@asura
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <fstream>
#include <sstream>
#include <windows.h> // windows api
#include "Contact.h"


// for manipulation in clearing certain lines in the terminal
void clearLines(int startLine, int numLines) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the cursor position to the start of the specified line
    COORD coord;
    coord.X = 0; // in terminal the x->0 is the upper left corner 
    coord.Y = startLine;
    SetConsoleCursorPosition(hConsole, coord);

    // Fill the specified number of lines with spaces
    for (int i = 0; i < numLines; ++i) {
        DWORD written;
        // i just pass for 200 columns, so if the input exceeded it will not be clear (based on my laptop screen)
        // i mean its not actually cleared i just overwrite the text in that specific line with spaces
        FillConsoleOutputCharacter(hConsole, ' ', 200, coord, &written);  

        // Reset attributes (make the console colors back to default)
        FillConsoleOutputAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, 200, coord, &written);  
        coord.Y++; // increment the line to clear/overwrite the next line
    }
}


enum ComparisonResult { 
    LESS,     // smaller value 
    GREATER,  // larger value
    EQUAL     // equal value
};


// used for sorting
// the following 3 comparator functions is used to compare the Contact objects
// in the contactList vector based on the fileter the user selected to view the contactList
bool compareContactByName(const Contact& contact1, const Contact& contact2) {
    std::string contactName1 = contact1.getName();
    std::string contactName2 = contact2.getName();

    // lowercase first the two contact name before comparing
    std::transform(contactName1.begin(), contactName1.end(), contactName1.begin(), ::tolower);
    std::transform(contactName2.begin(), contactName2.end(), contactName2.begin(), ::tolower);

    return contactName1 < contactName2;
}

bool compareContactByPhoneNumber(const Contact& contact1, const Contact& contact2) {
    std::string contactPhoneNumber1 = contact1.getPhoneNumber();
    std::string contactPhoneNumber2 = contact2.getPhoneNumber();

    // lowercase first the two phone number before comparing
    std::transform(contactPhoneNumber1.begin(), contactPhoneNumber1.end(), contactPhoneNumber1.begin(), ::tolower);
    std::transform(contactPhoneNumber2.begin(), contactPhoneNumber2.end(), contactPhoneNumber2.begin(), ::tolower);
    return contactPhoneNumber1 < contactPhoneNumber2;
}

bool compareContactByEmail(const Contact& contact1, const Contact& contact2) {
    std::string contactEmail1 = contact1.getEmail();
    std::string contactEmail2 = contact2.getEmail();

    // lowercase first the two phone number before comparing
    std::transform(contactEmail1.begin(), contactEmail1.end(), contactEmail1.begin(), ::tolower);
    std::transform(contactEmail2.begin(), contactEmail2.end(), contactEmail2.begin(), ::tolower);
    return contactEmail1 < contactEmail2;
}

// used for searching
// the following 3 comparator functions is used to compare(if equal) the Contact object to the search of the user
// in the contactList vector based on what filter the user selected to search in the contactList
ComparisonResult searchContactByName(const Contact& contact, const std::string& nameSearched) {
    std::string contactName = contact.getName();
    // make the contactName to lowercase
    std::transform(contactName.begin(), contactName.end(), contactName.begin(), ::tolower);

    if (nameSearched < contactName) { return LESS; }
    else if (nameSearched > contactName) { return GREATER; }
    else return EQUAL;
}

ComparisonResult searchContactByPhoneNumber(const Contact& contact, const std::string& phoneNumberSearched) {
    std::string contactPhoneNumber = contact.getPhoneNumber();
    // make the contactPhoneNumber to lowercase
    std::transform(contactPhoneNumber.begin(), contactPhoneNumber.end(), contactPhoneNumber.begin(), ::tolower);

    if (phoneNumberSearched < contactPhoneNumber) { return LESS; }
    else if (phoneNumberSearched > contactPhoneNumber) { return GREATER; }
    else return EQUAL;
}

ComparisonResult searchContactByEmail(const Contact& contact, const std::string& emailSearched) {
    std::string contactEmail = contact.getEmail();
    // make the contactEmail to lowercase
    std::transform(contactEmail.begin(), contactEmail.end(), contactEmail.begin(), ::tolower);

    if (emailSearched < contactEmail) { return LESS; }
    else if (emailSearched > contactEmail) { return GREATER; }
    else return EQUAL;
}


class ContactManager {
private:
    std::vector<Contact> contactList;  // stores the contacts
public:
    // functions to read and write to file
    void readContactsFromFile();   // load the contacts from the file
    void writeContactsToFile();    // save the contacts to the file

    // allias for the function pointers (for sorting and searching)
    using searchComparatorFunction = ComparisonResult (*)(const Contact&, const std::string&); 
    using sortComparatorFunction = bool (*)(const Contact&, const Contact&);

    // so basically it first creates the left sub arrays and after that along with that certain recursion
    // it will create the right sub array (for that certain left sub array) and if that right sub array still 
    // needed to be divided then it will be divided until it reaches the base case then just merge and sort it 
    // until the right sub array is sorted and merge to the original vector,
    // then merge and sorts the right sub array which calls it and its paired left sub array.
    void mergeSort(int start, int end, sortComparatorFunction compare);
    void merge(int start, int mid, int end, sortComparatorFunction compare); // helper method for mergeSort
    
    // sorting happens in_place meaning it happens inside the orignal container(vector in this case)
    // just that it is divided by a pivot(start, end, or random pos), which will be then placed in its correct place, 
    // wherein the left side of the pivot are elements that is less than the pivot and 
    // on the right side of the pivot are elements that is greater than the pivot (this is done by the helper function named partition),
    // so sorting and  partitioning of the elements happens the same time, unlike in mergesort where it need to create
    // temporary sub arrays until there is only one element in that sub array then it pop out in the call stack
    // to be sorted and merge. (bascally sorting and merging happens after the elements is divided)
    void quickSort(int start, int end, sortComparatorFunction compare);
    int partition(int start, int end, sortComparatorFunction compare); // helper method for quicksort

    // binary search is used to find a specific contact based on the users selected filter(name, phone number or email)
    // the users input should match the whole string in that field (regardless of its case).
    // how binary search works is that the container should be sorted first, then it checks if the 
    // input to find is greater than or less than the middle element (the first one to be compared to )
    // if the input is less than the middle element it discarded the right part and search the element in the left part
    // if the input is greater than the  middle element it discarded the left part and search the element in the right part
    // this will go until there is an element in the in the part where it is searching or when the element is found.
    void binarySearch(const std::string& contactDetail, searchComparatorFunction compare);

    // linear search is used when the user selected to input a keyword to find a contact
    // this will display all the contacts if the search input of the user is a substring of any of the
    // fields of the contact (name, phone number, email)
    void linearSearch(const std::string& searchKeyword);

    // functions that checks input from the user (made a regex for this functions)
    bool isValidPhoneNumber(const std::string& phoneNumber);
    bool isValidEmail(const std::string& email);
    bool isValidName(const std::string& name);

    // functions that manages the menus and the options inside it
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

// reads the contacts from the data file
void ContactManager::readContactsFromFile() {
    std::ifstream fhand("data/contacts.csv");

    std::string line; // container for every line in the csv file
    std::string name, phone_number, email; // container for every fields of the contact obj
    while (std::getline(fhand, line)) {
        std::istringstream contact(line); // break each lines into tokens

        std::getline(contact, name, ',');           // the first token is the name
        std::getline(contact, phone_number, ',');   // the second token is the phone number
        std::getline(contact, email);               // the third token is the email
        
        // put the contact into the list
        contactList.emplace_back(name, phone_number, email);
    }

    fhand.close(); // close the file
}

// overwrite all the old contents of the file
// and put the new contacts in the data file
void ContactManager::writeContactsToFile() {
    std::ofstream fhand("data/contacts.csv");

    std::string line;
    for (const auto& contact : contactList) {
        line = contact.name + "," + contact.phone_number + "," + contact.email + "\n";
        fhand << line;
    }

    fhand.close(); // close the file
}
    

void ContactManager::merge(int start, int mid, int end, sortComparatorFunction compare) {
    // initialize a temporary vector so that we don't modify the values in the original vector
    // while sorting and merging contacts (the size will be the size of the left and right array)
    std::vector<Contact> temp(end - start + 1);

    // k for the original array, 
    // l for the leftArray, 
    // r for the rightArray
    int l = start, r = mid + 1, k = 0; // indices
    
    // as long as there is a values in the left and right sub arrays we compare those values 
    // and put it in right order in the original list
    while (l <= mid && r <= end) {
        if (compare(contactList[l], contactList[r])) { // the function pointer all compare in ascending order
            temp[k++] = contactList[l++];
        }
        else {
            temp[k++] = contactList[r++];
        }
    }

    // put the remaining values in the left array to temp
    while (l <= mid) {
        temp[k++] = contactList[l++];
    }

    // put the remaining values in the right array to temp
    while (r <= end) {
        temp[k++] = contactList[r++];
    }

    // now we put the merge and sorted values in the temp array back to the original list(vector)
    // were only goint to put from in the start and end index
    for (int i = start; i <= end; i++) {
        contactList[i] = temp[i - start];  // lets say the start is 10 so if we minus i to 10 we get 0
    }

}

// I use the in place merge sort, where in I dont need to create and pass 
// the left and right arrays/vectors in this case in the  mergeSort function
void ContactManager::mergeSort(int start, int end, sortComparatorFunction compare) {

    // divide the vector until there is only one element left in the left and right array, 
    // then we merge the left and right sub array 
    if (start < end) {
        int mid = start + (end - start) / 2;  

        mergeSort(start, mid, compare); // left sub array
        mergeSort(mid+1, end, compare); // right sub array
        merge(start, mid, end, compare); // comapare and merge the left and right sub array
    }

}

int ContactManager::partition(int start, int end, sortComparatorFunction compare) {

    // the pivot well be the last element of the vector
    // it can also be in the mid or the beginning element
    Contact pivot = contactList[end];

    int pivot_pos = start; // kept track of the index of the pivot

    // compare all the elements except to the pivot except itself
    for (int i = start; i <= end - 1; i++) {

        if (compare(contactList[i], pivot)) {
            // swap the smaller elements to the left and bigger elements on the right
            Contact temp = contactList[pivot_pos];
            contactList[pivot_pos] = contactList[i];
            contactList[i] = temp;
            pivot_pos++; // increment the place of the pivot
        }
    }

    // put the pivot in its correct place
    Contact temp = contactList[pivot_pos]; // store the element, where the pivot should be placed
    contactList[pivot_pos] = contactList[end]; // place the pivot in its right position
    contactList[end] = temp; // the stored element will be placed in the previous pos of the pivot
    return pivot_pos; // return the index of the pivot
}

void ContactManager::quickSort(int start, int end, sortComparatorFunction compare) {
     
    if (end <= start) { return; } // base case
    
    int pivot = partition(start, end, compare);

    // left partition
    quickSort(start, pivot - 1, compare);

    // right partition
    quickSort(pivot + 1, end, compare);

}


void ContactManager::binarySearch(const std::string& contactDetail, searchComparatorFunction compare) {
    system("cls");
    int start = 0;
    int end = contactList.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        Contact contact = contactList[mid];

        // here we get the result from member function pointer that the user selected in the filter
        ComparisonResult comparisonResult = compare(contact, contactDetail);

        if (comparisonResult == LESS) { 
            // if the searched value is less than the mid value (discard the right part of the array)
            // then continue to search on the left side of the array 
            end = mid - 1;
        } 
        else if ( comparisonResult == GREATER) {
            // if the searched value is greater than the mid value (discard the left part of the array) 
            // then continue to search on the right side of the array
            start = mid + 1;
        } 
        else if (comparisonResult = EQUAL) {
            std::cout << "Contact Found!\n\n";
            std::cout << "Name: " << contact.name << "\n";
            std::cout << "Phone Number: " << contact.phone_number << "\n";
            std::cout << "Email: " << contact.email << "\n\n";
            return; // target found
        }
    }

    // target not found
    std::cout << "Contact Not Found!\n\n"; 
}

// linear search
void ContactManager::linearSearch(const std::string& searchKeyword) {
    system("cls");
    bool isSearchKeywordFound = false;

    std::cout << "Search Results: \n\n";

    // the find() method returns the position of the first occurence of 
    // substring if it is found if not it returns std::string::npos as the return value
    for (int i = 0; i < contactList.size(); i++)  {
        std::string contactName = contactList[i].name;
        std::string contactPhoneNumber = contactList[i].phone_number;
        std::string contactEmail = contactList[i].email;

        // make the contact details to lowercase
        // so that it will match the seacheKeyword regardless of the case
        std::transform(contactName.begin(), contactName.end(), contactName.begin(), ::tolower);
        std::transform(contactPhoneNumber.begin(), contactPhoneNumber.end(), contactPhoneNumber.begin(), ::tolower);
        std::transform(contactEmail.begin(), contactEmail.end(), contactEmail.begin(), ::tolower);

        // if the keyword searched by the user is find withind the 3 fields of the  
        // Contact obj. (name, phone_number, email) then we display that Contact
        if (contactName.find(searchKeyword) != std::string::npos ||
            contactPhoneNumber.find(searchKeyword) != std::string::npos ||
            contactEmail.find(searchKeyword) != std::string::npos ) 
        {
            isSearchKeywordFound = true;
            std::cout << "Name: " << contactList[i].name << "\n";
            std::cout << "Phone Number: " << contactList[i].phone_number << "\n";
            std::cout << "Email: " << contactList[i].email << "\n";
            std::cout << "================================================\n\n";
        }
    }

    // if the searched keyword is not found
    if (!isSearchKeywordFound) {
        std::cout << "No Results Found...\n\n";
    }
}

// check if the input phone number is valid
bool ContactManager::isValidPhoneNumber(const std::string& phoneNumber) {
    // regex pattern for some phone number patterns in the philippines
    // pipe | for alternation, or you can think of it as or
    std::regex phoneNumberPattern("^(02\\d{7}|\\d{3}\\d{7}|\\d{4}\\d{6,7})$");

    if (!std::regex_match(phoneNumber, phoneNumberPattern)) {
        std::cout << "\n\nPlease enter a valid phone number...\n";
        system("pause");
        return false;
    }
    return true;
}

bool ContactManager::isValidEmail(const std::string& email) {
    // regex pattern for simple/basic email validation string
    std::regex emailPattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

    // Use std::regex_match to check if the email matches the emailPattern 
    if (!std::regex_match(email, emailPattern)) {
        std::cout << "\n\nPlease enter a valid email...\n"; 
        system("pause");
        return false;
    }
    return true;
}

bool ContactManager::isValidName(const std::string& name) {
    // name should only containns letters and spaces
    // minimum length of name is 3 and max is 20
    std::regex namePattern("^[a-zA-Z ]{3,20}$");

    if (!std::regex_match(name, namePattern)) {
        std::cout << "\n\nName should only contain letters and spaces!\n";
        system("pause");
        return false;
    }

    return true;
}

// this is the starting point of the program 
// the startmenu
void ContactManager::menu() {
    // firstly read all the contacts in the file
    // so that the use can interact with it
    readContactsFromFile();

    std::string command; // container for the user selected option
    while (true) {
        system("cls");
        std::cout << "Contact Manager System Menu\n";
        std::cout << "[M] Manage Contact\n";
        std::cout << "[V] View Contact\n";
        std::cout << "[S] Search Contact\n";
        std::cout << "[E] Exit\n"; 
        std::cout << "Command: ";
        std::getline(std::cin, command);

        // convert the command to uppercase;
        std::transform(command.begin(), command.end(), command.begin(), ::toupper);

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
            // once the user choose to exists the program
            // write all the changes that the user made 
            // in the data file ( this overwrite the old data and write updated one)
            writeContactsToFile();
            return;
        } 
        else {
            std::cout << "\n\nInvalid Command\n";
            system("pause");
        }
    }

}

void ContactManager::manageContactMenu() {

    std::string command;

    while (true) {
        system("cls");
        std::cout << "Manage Contacts Menu\n";
        std::cout << "[A] Add Contact\n";
        std::cout << "[E] Edit Contact\n";
        std::cout << "[D] Delete Contact\n";
        std::cout << "[B] Back\n";

        std::cout << "Command: ";
        std::getline(std::cin, command);

        // convert the command to uppercase
        std::transform(command.begin(), command.end(), command.begin(), ::toupper);

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

}

void ContactManager::addContact() {
    std::string addMoreContact;
    std::string name;
    std::string phone_number;
    std::string email;

    while (true) {
        system("cls");

        std::cout << "Add Contact\n\n";
        
        // get a valid contact name
        while (true) {

            std::cout << "Enter contact name: "; 
            std::getline(std::cin, name);
            
            if(isValidName(name)) { break; }
            clearLines(2, 7);
        }

        // get a valid contact phone number
        while (true) {

            std::cout << "Enter contact phone number: ";
            std::getline(std::cin, phone_number);

            if(isValidPhoneNumber(phone_number)) { break; }
            clearLines(3, 8);
        }
        
        // get a valid contact email
        while (true) {

            std::cout << "Enter contact email: ";
            std::getline(std::cin, email);

            if(isValidEmail(email)) { break; }
            clearLines(4, 9);
        }

        // create a contact obj
        Contact contact = Contact(name, phone_number, email);

        // add the contact obj to the contactList
        // i use emplace_back as its much more efficient when adding dynamic objects
        contactList.emplace_back(contact);

        // checks if the user wants to add more contacts
        while (true) {
            std::cout << "\n\nDo you want to add more contact[y/n]: ";
            std::getline(std::cin, addMoreContact);
            std::transform(addMoreContact.begin(), addMoreContact.end(), addMoreContact.begin(), ::tolower);

            if (addMoreContact == "y") { break; }
            else if (addMoreContact == "n") { return; }
            clearLines(5, 8);
        }
    }
}

void ContactManager::editContact() {
    std::string editContact;
    std::string editAnotherContact;
    bool contactEdited;

    std::string name;
    std::string phone_number;
    std::string email;
    while (true) {
        system("cls");

        std::cout << "Edit Contact\n\n";

        // get the contact name to be edited
        std::cout << "Enter contact name to edit: ";
        std::getline(std::cin, editContact);
        
        // make the input to lowercase
        std::transform(editContact.begin(), editContact.end(), editContact.begin(), ::tolower);

        // find the contact the user wants to edit in the contactList
        for (int i = 0; i < contactList.size(); i++) {
            std::string contactName = contactList[i].name;

            //  make the contact name to lowercase
            std::transform(contactName.begin(), contactName.end(), contactName.begin(), ::tolower);
            if (editContact == contactName) {

                // edit contact name
                while (true) {
                    std::cout << "Enter new contact name: "; 
                    std::getline(std::cin, name);

                    if (isValidName(name)) { break; }
                    clearLines(3, 8);
                }
                contactList[i].name = name;

                // edit contact phone number
                while (true) {
                    std::cout << "Enter new contact phone number: ";
                    std::getline(std::cin, phone_number);

                    if (isValidPhoneNumber(phone_number)) { break; }
                    clearLines(4, 9);
                }
                contactList[i].phone_number = phone_number;
                
                // edit contact email
                while (true) {
                    std::cout << "Enter new contact email: ";
                    std::getline(std::cin, email);

                    if (isValidEmail(email)) { break; }
                    clearLines(5, 10);
                }
                contactList[i].email = email;

                contactEdited = true;
                break; // exit the loop after the contact is edited
            }
        }

        if (contactEdited) {
            std::cout << "\n\nContact Edited Successfully!\n";
            contactEdited = false;
        } else {
            std::cout << "\n\n\n\nContact Not Found!\n";
        }

        // ask the user if they want to edit another contact
        while (true) {
            std::cout << "Do you want to edit another contact[y/n]: ";
            std::getline(std::cin, editAnotherContact);
            std::transform(editAnotherContact.begin(), editAnotherContact.end(), editAnotherContact.begin(), ::tolower);

            if (editAnotherContact == "y") { break; }
            else if (editAnotherContact == "n") { return; }
            clearLines(8, 9);
        }
    }
}

void ContactManager::deleteContact() {
    std::string deleteContact;
    std::string deleteAnotherContact;
    bool contactDeleted = false;
    while (true) {
        system("cls");

        std::cout << "Delete Contact\n\n";

        // get the contact name to be deleted
        std::cout << "Enter contact name to delete: ";
        std::getline(std::cin, deleteContact);

        // make the input to lowercase
        std::transform(deleteContact.begin(), deleteContact.end(), deleteContact.begin(), ::tolower);

        // find the contact the user wants to delete in the contactList
        for (int i = 0; i < contactList.size(); i++) {
            std::string contactName = contactList[i].name;

            //  make the contact name to lowercase
            std::transform(contactName.begin(), contactName.end(), contactName.begin(), ::tolower);
            if (deleteContact == contactName) {

                // delete the contact
                contactList.erase(contactList.begin() + i);
                contactDeleted = true;
                break; // exit the loop after the contact is edited
            }
        }

        if (contactDeleted) {
            std::cout << "\n\nContact Deleted Successfully!\n";
            contactDeleted = false;
        } else {
            std::cout << "\n\nContact Not Found!\n";
        }

        // ask the user if they want to edit another contact
        while (true) {
            std::cout << "Do you want to delete another contact[y/n]: ";
            std::getline(std::cin, deleteAnotherContact);
            std::transform(deleteAnotherContact.begin(), deleteAnotherContact.end(), deleteAnotherContact.begin(), ::tolower);

            if (deleteAnotherContact == "y") { break; }
            else if (deleteAnotherContact == "n") { return; }
            clearLines(6, 7);
        }
    }
}

void ContactManager::viewContactMenu() {
    std::string command;
    while (true) {
        system("cls");

        std::cout << "View Contacts Menu\n";
        std::cout << "[N] View By Name\n";
        std::cout << "[P] View By Phone Number\n";
        std::cout << "[E] View By Email\n";
        std::cout << "[B] Back\n";
        std::cout << "Command: ";
        std::getline(std::cin, command);

        // convert the command to uppercase
        std::transform(command.begin(), command.end(), command.begin(), ::toupper);

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

}

// prints the contact based on the filter choosen by the user
void ContactManager::printContactList(std::string& filter) {
    // function pointer will point to a comapartor function
    // based on how the user wants to view the contactList
    bool (*comparatorFunction) (const Contact& contact1, const Contact& contact2);

    if (filter == "N") { comparatorFunction = compareContactByName; }
    else if (filter == "P") { comparatorFunction = compareContactByPhoneNumber; }
    else if (filter == "E") { comparatorFunction = compareContactByEmail; }

    int size = contactList.size();
    mergeSort(0, size - 1, comparatorFunction);

    system("cls");
    std::cout << "================ CONTACT LIST ==================\n\n";

    if (contactList.empty()) {
        std::cout << "\n\nYou have no contacts recorded...\n\n";
    }

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

        std::cout << "Search Contacts Menu \n";
        std::cout << "[N] Search By Name\n";
        std::cout << "[P] Search By Phone Number\n";
        std::cout << "[E] Search By Email\n";
        std::cout << "[K] Search By Keyword\n";
        std::cout << "[B] Back\n";
        std::cout << "Command: ";
        std::getline(std::cin, command);

        // convert the command to uppercase
        std::transform(command.begin(), command.end(), command.begin(), ::toupper);

        bool isCommand = command == "N" || command == "P" || command == "E" || command == "K"; 

        if (isCommand) {
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
    system("cls");

    // function pointer will point to a comapartor function
    // based on what filter the user selected to search the contactList
    
    // used for sorting
    bool (*sortComparatorFunction)(const Contact& contact1, const Contact& contact2);

    // used for searching 
    ComparisonResult (*searchComparatorFunction) (const Contact& contact, const std::string& contactDetail);


    std::string searchPrompt;
    if (filter == "K") {
        std::cout << "Search By keyword";
        searchPrompt = "\n\nEnter keyword: ";    
    }
    else if (filter == "N") { 
        std::cout << "Search By Name";
        searchPrompt = "\n\nEnter Contact Name: ";
        sortComparatorFunction = compareContactByName;
        searchComparatorFunction = searchContactByName; 
    }
    else if (filter == "P") { 
        std::cout << "Search By Phone Number";
        searchPrompt = "\n\nEnter Contact Phone Number: ";
        sortComparatorFunction = compareContactByPhoneNumber;
        searchComparatorFunction = searchContactByPhoneNumber;
    }
    else if (filter == "E") { 
        std::cout << "Search By Email";
        searchPrompt = "\n\nEnter Contact Email: ";
        sortComparatorFunction = compareContactByEmail;
        searchComparatorFunction = searchContactByEmail;
    }


    // get the search input of the user
    std::string contactDetail;
    std::cout << searchPrompt;
    std::getline(std::cin, contactDetail);
    std::transform(contactDetail.begin(), contactDetail.end(), contactDetail.begin(), ::tolower);


    if (filter == "K") { 
        linearSearch(contactDetail);
    } 
    else {
        // sort contact list using qucksort
        quickSort(0, contactList.size() - 1, sortComparatorFunction);

        // search contact using binary search
        binarySearch(contactDetail, searchComparatorFunction);

    } 

    system("pause");

}

int main() {
    ContactManager contactManager = ContactManager();
    contactManager.menu();
    return 0;
}
