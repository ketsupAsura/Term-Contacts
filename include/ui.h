//ketsup@asura matthew
#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <windows.h>

#include "contact.h"

class UserInterface
{

public:
    static std::string mainMenuInput();
    static std::string viewContactMenuInput();
    static std::string manageContactMenuInput();
    static std::string searchContactMenuInput();
    static void displayContacts(const std::vector<Contact>& contactList, int displayType = 0);
    static void clearLines(int startLine, int numLines);

};
