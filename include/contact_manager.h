//ketsup@asura/matthew
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

#include "contact.h"
#include "unicode_ui.h"
//#include "ui.h"


enum ComparisonResult 
{ 
    LESS,     // smaller value 
    GREATER,  // larger value
    EQUAL     // equal value
};

// for manipulation in clearing certain lines in the terminal
void clearLines(int startLine, int numLines);

// for sorting
bool compareContactByName(const Contact& contact1, const Contact& contact2);
bool compareContactByPhoneNumber(const Contact& contact1, const Contact& contact2);
bool compareContactByEmail(const Contact& contact1, const Contact& contact2); 

// for searching
ComparisonResult searchContactByName(const Contact& contact, const std::string& nameSearched);
ComparisonResult searchContactByPhoneNumber(const Contact& contact, const std::string& phoneNumberSearched);
ComparisonResult searchContactByEmail(const Contact& contact, const std::string& emailSearched);

class ContactManager
{
private:
    std::vector<Contact> contactList;  // stores the contacts
    
public:
    ContactManager(std::vector<Contact>& contacts);
    const std::vector<Contact>& getContactList() const;

    // allias for the function pointers (for sorting and searching)
    using searchComparatorFunction = ComparisonResult (*)(const Contact&, const std::string&); 
    using sortComparatorFunction = bool (*)(const Contact&, const Contact&);

    void mergeSort(int start, int end, sortComparatorFunction compare);
    void merge(int start, int mid, int end, sortComparatorFunction compare); // helper method for mergeSort
    
    void quickSort(int start, int end, sortComparatorFunction compare);
    int partition(int start, int end, sortComparatorFunction compare); // helper method for quicksort

    void binarySearch(const std::string& contactDetail, searchComparatorFunction compare);
    void linearSearch(const std::string& searchKeyword);

    // methods that checks input from the user (made a regex for this functions)
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
