//ketsup@asura//matthew
#pragma once

#include <vector>
#include <fstream>
#include <sstream>

#include "contact.h"

class FileIO 
{

public:
    static std::vector<Contact> loadContacts(const std::string& filename);
    static void saveContacts(const std::string& filename, const std::vector<Contact>& contacts);

};
