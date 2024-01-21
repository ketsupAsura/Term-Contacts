// ketsup@asura/matthew
#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <windows.h>

// unicode printing
#include <io.h> 
#include <fcntl.h> // file control operation(from c standard library)

#include "contact.h"

class UserInterface
{

public:
    static std::string mainMenuInput();
    static std::string viewContactMenuInput();
    static std::string manageContactMenuInput();
    static std::string searchContactMenuInput();
    static void displayContacts(const std::vector<Contact>& contactList, int displayType = 0);
    static void warningMessage();

    // Terminal Console output manipulation
    static void clearLines(const int& startLine, const int& numLines);
    static void gotoxy(const short int& x, const short int& y);

};
