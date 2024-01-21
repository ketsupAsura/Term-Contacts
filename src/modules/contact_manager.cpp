// ketsup@asura/matthew

#include "contact_manager.h"

bool compareContactByName(const Contact& contact1, const Contact& contact2) 
{
    std::string contactName1 = contact1.getName();
    std::string contactName2 = contact2.getName();

    // lowercase first the two contact name before comparing
    std::transform(contactName1.begin(), contactName1.end(), contactName1.begin(), ::tolower);
    std::transform(contactName2.begin(), contactName2.end(), contactName2.begin(), ::tolower);

    return contactName1 < contactName2;
}

bool compareContactByPhoneNumber(const Contact& contact1, const Contact& contact2) 
{
    std::string contactPhoneNumber1 = contact1.getPhonenumber();
    std::string contactPhoneNumber2 = contact2.getPhonenumber();

    return contactPhoneNumber1 < contactPhoneNumber2;
}

bool compareContactByEmail(const Contact& contact1, const Contact& contact2)
{
    std::string contactEmail1 = contact1.getEmail();
    std::string contactEmail2 = contact2.getEmail();

    // lowercase first the two email before comparing
    std::transform(contactEmail1.begin(), contactEmail1.end(), contactEmail1.begin(), ::tolower);
    std::transform(contactEmail2.begin(), contactEmail2.end(), contactEmail2.begin(), ::tolower);
    return contactEmail1 < contactEmail2;
}

ComparisonResult searchContactByName(const Contact& contact, const std::string& nameSearched) 
{
    std::string contactName = contact.getName();

    // make the contactName to lowercase
    std::transform(contactName.begin(), contactName.end(), contactName.begin(), ::tolower);

    if (nameSearched < contactName) { return LESS; }
    else if (nameSearched > contactName) { return GREATER; }
    else return EQUAL;
}

ComparisonResult searchContactByPhoneNumber(const Contact& contact, const std::string& phoneNumberSearched) 
{
    std::string contactPhoneNumber = contact.getPhonenumber();

    if (phoneNumberSearched < contactPhoneNumber) { return LESS; }
    else if (phoneNumberSearched > contactPhoneNumber) { return GREATER; }
    else return EQUAL;
}

ComparisonResult searchContactByEmail(const Contact& contact, const std::string& emailSearched) 
{
    std::string contactEmail = contact.getEmail();

    // make the contactEmail to lowercase
    std::transform(contactEmail.begin(), contactEmail.end(), contactEmail.begin(), ::tolower);

    if (emailSearched < contactEmail) { return LESS; }
    else if (emailSearched > contactEmail) { return GREATER; }
    else return EQUAL;
}

//  constructor
ContactManager::ContactManager(std::vector<Contact>& contacts) : contactList(contacts) {}

// returns the contactlist
const std::vector<Contact>& ContactManager::getContactList() const { return contactList; }

void ContactManager::merge(int start, int mid, int end, sortComparatorFunction compare)
{
    // initialize a temporary vector so that we don't modify the values in the original vector
    // while sorting and merging contacts (the size will be the size of the left and right array)
    std::vector<Contact> temp(end - start + 1);

    // k for the original array, 
    // l for the leftArray, 
    // r for the rightArray
    int l = start, r = mid + 1, k = 0; // indices
    
    // as long as there is a values in the left and right sub arrays we compare those values 
    // and put it in right order in the original list
    while (l <= mid && r <= end)
    {
        if (compare(contactList[l], contactList[r]))
        { // the function pointer all compare in ascending order
            temp[k++] = contactList[l++];
        }
        else 
        {
            temp[k++] = contactList[r++];
        }
    }

    // put the remaining values in the left array to temp
    while (l <= mid)
    {
        temp[k++] = contactList[l++];
    }

    // put the remaining values in the right array to temp
    while (r <= end)
    {
        temp[k++] = contactList[r++];
    }

    // now we put the merge and sorted values in the temp array back to the original list(vector)
    // were only goint to put from in the start and end index
    for (int i = start; i <= end; i++)
    {
        contactList[i] = temp[i - start];  // lets say the start is 10 so if we minus i to 10 we get 0
    }

}

// I use the in place merge sort, where in I dont need to create and pass 
// the left and right arrays/vectors in this case in the  mergeSort function
void ContactManager::mergeSort(int start, int end, sortComparatorFunction compare)
{

    // divide the vector until there is only one element left in the left and right array, 
    // then we merge the left and right sub array 
    if (start < end)
    {
        int mid = start + (end - start) / 2;  

        mergeSort(start, mid, compare); // left sub array
        mergeSort(mid+1, end, compare); // right sub array
        merge(start, mid, end, compare); // comapare and merge the left and right sub array
    }

}

int ContactManager::partition(int start, int end, sortComparatorFunction compare) 
{
    // the pivot well be the last element of the vector
    // it can also be in the mid or the beginning element
    Contact pivot = contactList[end];

    int pivot_pos = start; // kept track of the index of the pivot

    // compare all the elements except to the pivot except itself
    for (int i = start; i <= end - 1; i++)
    {
        if (compare(contactList[i], pivot))
        {
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

void ContactManager::quickSort(int start, int end, sortComparatorFunction compare)
{
    if (end <= start) { return; } // base case
    
    int pivot = partition(start, end, compare);

    // left partition
    quickSort(start, pivot - 1, compare);

    // right partition
    quickSort(pivot + 1, end, compare);

}


void ContactManager::binarySearch(const std::string& contactDetail, searchComparatorFunction compare) 
{
    system("cls");
    int start = 0;
    int end = contactList.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        Contact contact = contactList[mid];

        // here we get the result from member function pointer that the user selected in the filter
        ComparisonResult comparisonResult = compare(contact, contactDetail);

        if (comparisonResult == LESS)
        { 
            // if the searched value is less than the mid value (discard the right part of the array)
            // then continue to search on the left side of the array 
            end = mid - 1;
        } 
        else if ( comparisonResult == GREATER)
        {
            // if the searched value is greater than the mid value (discard the left part of the array) 
            // then continue to search on the right side of the array
            start = mid + 1;
        } 
        else if (comparisonResult = EQUAL)
        {
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
void ContactManager::linearSearch(const std::string& searchKeyword) 
{
    system("cls");
    std::vector<Contact> results; // will contain the search results

    // the find() method returns the position of the first occurence of 
    // substring if it is found if not it returns std::string::npos as the return value
    for (auto contact : contactList)
    {
        std::string contactName = contact.name;
        std::string contactPhoneNumber = contact.phone_number;
        std::string contactEmail = contact.email;

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
            results.emplace_back(contact);
        }
    }
    UserInterface::displayContacts(results, 1);
}

// check if the input phone number is valid
bool ContactManager::isValidPhoneNumber(const std::string& phoneNumber)
{
    // regex pattern for some phone number patterns in the philippines
    // pipe | for alternation, or you can think of it as or
    std::regex phoneNumberPattern("^(02\\d{7}|\\d{3}\\d{7}|\\d{4}\\d{6,7})$");

    if (!std::regex_match(phoneNumber, phoneNumberPattern))
    {
        std::cout << "\n\nPlease enter a valid phone number...\n";
        system("pause");
        return false;
    }
    return true;
}

bool ContactManager::isValidEmail(const std::string& email)
{
    // regex pattern for simple/basic email validation string
    std::regex emailPattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

    // Use std::regex_match to check if the email matches the emailPattern 
    if (!std::regex_match(email, emailPattern))
    {
        std::cout << "\n\nPlease enter a valid email...\n"; 
        system("pause");
        return false;
    }
    return true;
}

bool ContactManager::isValidName(const std::string& name) 
{
    // name should only containns letters and spaces
    // minimum length of name is 3 and max is 20
    std::regex namePattern("^[a-zA-Z ]{3,20}$");

    if (!std::regex_match(name, namePattern)) 
    {
        std::cout << "\n\nName should only contain letters and spaces!\n";
        system("pause");
        return false;
    }

    return true;
}


void ContactManager::manageContactMenu() 
{
    std::string command;

    while (true)
    {
        system("cls");
        command = UserInterface::manageContactMenuInput();

        if (command == "A") { addContact(); } 
        else if (command == "E") { editContact(); } 
        else if (command == "D") { deleteContact(); } 
        else if (command == "B") { return; } 
        else { UserInterface::warningMessage(); }
    }

}

void ContactManager::addContact() 
{
    std::string addMoreContact;
    std::string name;
    std::string phone_number;
    std::string email;

    while (true)
    {
        system("cls");

        std::cout << "Add Contact\n\n";
        
        // get a valid contact name
        while (true)
        {

            std::cout << "Enter contact name: "; 
            std::getline(std::cin, name);
            
            if(isValidName(name)) { break; }
            UserInterface::clearLines(2, 7);
        }

        // get a valid contact phone number
        while (true)
        {

            std::cout << "Enter contact phone number: ";
            std::getline(std::cin, phone_number);

            if(isValidPhoneNumber(phone_number)) { break; }
            UserInterface::clearLines(3, 8);
        }
        
        // get a valid contact email
        while (true)
        {

            std::cout << "Enter contact email: ";
            std::getline(std::cin, email);

            if(isValidEmail(email)) { break; }
            UserInterface::clearLines(4, 9);
        }

        // create a contact obj
        Contact contact = Contact(name, phone_number, email);

        // add the contact obj to the contactList
        // i use emplace_back as its much more efficient when adding dynamic objects
        contactList.emplace_back(contact);

        // checks if the user wants to add more contacts
        while (true)
        {
            std::cout << "\n\nDo you want to add more contact[y/n]: ";
            std::getline(std::cin, addMoreContact);
            std::transform(addMoreContact.begin(), addMoreContact.end(), addMoreContact.begin(), ::tolower);

            if (addMoreContact == "y") { break; }
            else if (addMoreContact == "n") { return; }
            UserInterface::clearLines(5, 8);
        }
    }
}

void ContactManager::editContact() 
{
    std::string editContact;
    std::string editAnotherContact;
    bool contactEdited;

    std::string name;
    std::string phone_number;
    std::string email;
    while (true)
    {
        system("cls");

        std::cout << "Edit Contact\n\n";

        // get the contact name to be edited
        std::cout << "Enter contact name to edit: ";
        std::getline(std::cin, editContact);
        
        // make the input to lowercase
        std::transform(editContact.begin(), editContact.end(), editContact.begin(), ::tolower);

        // find the contact the user wants to edit in the contactList
        for (int i = 0; i < contactList.size(); i++) 
        {
            std::string contactName = contactList[i].name;

            //  make the contact name to lowercase
            std::transform(contactName.begin(), contactName.end(), contactName.begin(), ::tolower);
            if (editContact == contactName)
            {

                // edit contact name
                while (true)
                {
                    std::cout << "Enter new contact name: "; 
                    std::getline(std::cin, name);

                    if (isValidName(name)) { break; }
                    UserInterface::clearLines(3, 8);
                }
                contactList[i].name = name;

                // edit contact phone number
                while (true)
                {
                    std::cout << "Enter new contact phone number: ";
                    std::getline(std::cin, phone_number);

                    if (isValidPhoneNumber(phone_number)) { break; }
                    UserInterface::clearLines(4, 9);
                }
                contactList[i].phone_number = phone_number;
                
                // edit contact email
                while (true)
                {
                    std::cout << "Enter new contact email: ";
                    std::getline(std::cin, email);

                    if (isValidEmail(email)) { break; }
                    UserInterface::clearLines(5, 10);
                }
                contactList[i].email = email;

                contactEdited = true;
                break; // exit the loop after the contact is edited
            }
        }

        if (contactEdited) 
        {
            std::cout << "\n\nContact Edited Successfully!\n";
            contactEdited = false;
        }
        else
        {
            std::cout << "\n\n\n\nContact Not Found!\n";
        }

        // ask the user if they want to edit another contact
        while (true)
        {
            std::cout << "Do you want to edit another contact[y/n]: ";
            std::getline(std::cin, editAnotherContact);
            std::transform(editAnotherContact.begin(), editAnotherContact.end(), editAnotherContact.begin(), ::tolower);

            if (editAnotherContact == "y") { break; }
            else if (editAnotherContact == "n") { return; }
            UserInterface::clearLines(8, 9);
        }
    }
}

void ContactManager::deleteContact() 
{
    std::string deleteContact;
    std::string deleteAnotherContact;
    bool contactDeleted = false;
    while (true)
    {
        system("cls");

        std::cout << "Delete Contact\n\n";

        // get the contact name to be deleted
        std::cout << "Enter contact name to delete: ";
        std::getline(std::cin, deleteContact);

        // make the input to lowercase
        std::transform(deleteContact.begin(), deleteContact.end(), deleteContact.begin(), ::tolower);

        // find the contact the user wants to delete in the contactList
        for (int i = 0; i < contactList.size(); i++) 
        {
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

        if (contactDeleted) 
        {
            std::cout << "\n\nContact Deleted Successfully!\n";
            contactDeleted = false;
        }
        else
        {
            std::cout << "\n\nContact Not Found!\n";
        }

        // ask the user if they want to edit another contact
        while (true) 
        {
            std::cout << "Do you want to delete another contact[y/n]: ";
            std::getline(std::cin, deleteAnotherContact);
            std::transform(deleteAnotherContact.begin(), deleteAnotherContact.end(), deleteAnotherContact.begin(), ::tolower);

            if (deleteAnotherContact == "y") { break; }
            else if (deleteAnotherContact == "n") { return; }
            UserInterface::clearLines(6, 7);
        }
    }
}

void ContactManager::viewContactMenu() 
{
    std::string command;
    while (true) 
    {
        system("cls");
        command = UserInterface::viewContactMenuInput();

        if (command == "N" || command == "P" || command == "E") { printContactList(command); } 
        else if (command == "B") { return;} 
        else { UserInterface::warningMessage(); }
    }

}

// prints the contact based on the filter choosen by the user
void ContactManager::printContactList(std::string& filter) 
{
    // function pointer will point to a comapartor function
    // based on how the user wants to view the contactList
    bool (*comparatorFunction) (const Contact& contact1, const Contact& contact2);

    if (filter == "N") { comparatorFunction = compareContactByName; }
    else if (filter == "P") { comparatorFunction = compareContactByPhoneNumber; }
    else if (filter == "E") { comparatorFunction = compareContactByEmail; }

    int size = contactList.size();
    mergeSort(0, size - 1, comparatorFunction);

    UserInterface::displayContacts(contactList);
}

// menu for searching contacts
void ContactManager::searchContactMenu() 
{
    std::string command;

    while (true)
    {
        system("cls");
        command = UserInterface::searchContactMenuInput();

        bool isCommand = command == "N" || command == "P" || command == "E" || command == "K"; 

        if (isCommand) { searchContactList(command); } 
        else if (command == "B") { return; } 
        else { UserInterface::warningMessage(); }
    }
}


void ContactManager::searchContactList(std::string& filter) 
{
    system("cls");

    // function pointer will point to a comapartor function
    // based on what filter the user selected to search the contactList
    
    // used for sorting
    bool (*sortComparatorFunction)(const Contact& contact1, const Contact& contact2);

    // used for searching 
    ComparisonResult (*searchComparatorFunction) (const Contact& contact, const std::string& contactDetail);


    std::string searchPrompt;
    if (filter == "K") 
    {
        std::cout << "Search By keyword";
        searchPrompt = "\n\nEnter keyword: ";    
    }
    else if (filter == "N")
    { 
        std::cout << "Search By Name";
        searchPrompt = "\n\nEnter Contact Name: ";
        sortComparatorFunction = compareContactByName;
        searchComparatorFunction = searchContactByName; 
    }
    else if (filter == "P")
    { 
        std::cout << "Search By Phone Number";
        searchPrompt = "\n\nEnter Contact Phone Number: ";
        sortComparatorFunction = compareContactByPhoneNumber;
        searchComparatorFunction = searchContactByPhoneNumber;
    }
    else if (filter == "E")
    { 
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


    if (filter == "K") { linearSearch(contactDetail); } 
    else {
        // sort contact list using qucksort
        quickSort(0, contactList.size() - 1, sortComparatorFunction);

        // search contact using binary search
        binarySearch(contactDetail, searchComparatorFunction);

        system("pause");
    } 

}

