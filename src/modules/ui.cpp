#include "ui.h"

std::string UserInterface::mainMenuInput()
{
    system("color 02");
    std::string command;

    std::cout << "=======================================\n";
    std::cout << "||    Contact Manager System Menu    ||\n";
    std::cout << "=======================================\n";
    std::cout << "|| [M] Manage Contact                ||\n";
    std::cout << "|| [V] View Contact                  ||\n";
    std::cout << "|| [S] Search Contact                ||\n";
    std::cout << "|| [E] Exit                          ||\n"; 
    std::cout << "=======================================\n";
    std::cout << "Command: ";
    std::getline(std::cin, command);

    // convert the command to uppercase;
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);
    
    return command;
}

std::string UserInterface::manageContactMenuInput()
{
    system("color 02");
    std::string command;
    std::cout << "======================================\n";
    std::cout << "||       Manage Contacts Menu       ||\n";
    std::cout << "======================================\n";
    std::cout << "|| [A] Add Contact                  ||\n";
    std::cout << "|| [E] Edit Contact                 ||\n";
    std::cout << "|| [D] Delete Contact               ||\n";
    std::cout << "|| [B] Back                         ||\n";
    std::cout << "======================================\n";
    std::cout << "Command: ";
    std::getline(std::cin, command);

    // convert the command to uppercase
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);

    return command;
}

std::string UserInterface::viewContactMenuInput()
{
    system("color 02");

    std::string command;
    std::cout << "======================================\n";
    std::cout << "||        View Contacts Menu        ||\n";
    std::cout << "======================================\n";
    std::cout << "|| [N] View By Name                 ||\n";
    std::cout << "|| [P] View By Phone Number         ||\n";
    std::cout << "|| [E] View By Email                ||\n";
    std::cout << "|| [B] Back                         ||\n";
    std::cout << "======================================\n";
    std::cout << "Command: ";
    std::getline(std::cin, command);

    // convert the command to uppercase
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);
    
    return command;
}

std::string UserInterface::searchContactMenuInput()
{
    system("color 02");
    std::string command;
    std::cout << "======================================\n";
    std::cout << "||       Search Contacts Menu       ||\n";
    std::cout << "======================================\n";
    std::cout << "|| [N] Search By Name               ||\n";
    std::cout << "|| [P] Search By Phone Number       ||\n";
    std::cout << "|| [E] Search By Email              ||\n";
    std::cout << "|| [K] Search By Keyword            ||\n";
    std::cout << "|| [B] Back                         ||\n";
    std::cout << "======================================\n";
    std::cout << "Command: ";
    std::getline(std::cin, command);

    // convert the command to uppercase
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);

    return command;
}

void UserInterface::displayContacts(const std::vector<Contact>& contactList, int displayType)
{
    /* displayType
    *  Values: default 0
    *  0 =  viewing
    *  1 =  searching
    */

    system("color 02");

    std::string title, empty;
    if (displayType == 0)
    {
        title = "CONTACT LIST ";                   // prompt for the title of the table 
        empty = " No Recorded Contacts... ";   // prompt when the contacts is empty
    }
    else 
    {
        title = "SEARCH RESULT";                   // prompt for the title of the table 
        empty = " No Results Found... ====";   // prompt when the contacts is empty
    }

    std::cout << "\n == " << title << " ======================================================================================\n";
    std::cout << " ||            Name            ||      Telephone Number      ||                 Email                 ||\n";
    std::cout << " =======================================================================================================\n";

    if (contactList.empty()) 
    {
        std::cout << " ||                                                                                                   ||\n";
        std::cout << " ==" << empty << "============================================================================\n\n";
    } 
    else 
    {
        for (auto contact : contactList)
        {
            printf(" || %-27s|| %-27s|| %-38s||\n", contact.getName().c_str(), contact.getPhonenumber().c_str(), contact.getEmail().c_str());
        }
        std::cout << " =======================================================================================================\n\n";

    }

    std::cout << " ";
}

void UserInterface::warningMessage() // warning message for invalid menu options
{

    std::cout << "\n\n";
    std::cout << " == Warning ====================\n";
    std::cout << " ||      Invalid Command      ||\n";
    std::cout << " ===============================\n";
    std::cout << "  "; 
    system("pause");

}

// for manipulation in clearing certain lines in the terminal
void UserInterface::clearLines(int startLine, int numLines)
{
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
