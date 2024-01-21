#include "unicode_ui.h"

/* TODO:
 * add ui for adding, deleting, editing of contact 
 * add ui for individual searching(the one that uses binary search)
*/

std::string UserInterface::mainMenuInput()
{
    /* NOTE:
     * by the i want to set it to 16 bits but cmd doesn't support it, only windows terminal
     * with 16 bits i can print more unicodes like this '⚠'
    */

    // make the stdout stream use 8 bit unicode
    _setmode(_fileno(stdout), _O_U8TEXT);

    std::string command;

    // L -> we are to print a wide string literal
    std::wcout << L"\n"; // 0y
    std::wcout << L" ┌─────────────────────────────────────┐\n"; // 1y
    std::wcout << L" │       Contact Manager System        │\n"; // 2y
    std::wcout << L" └─────────────────────────────────────┘\n"; // 3y
    std::wcout << L" ┌─ Main Menu ─────────────────────────┐\n"; // 4y
    std::wcout << L" │ [M] Manage Contact                  │\n"; // 5y
    std::wcout << L" │ [V] View Contact                    │\n"; // 6y
    std::wcout << L" │ [S] Search Contact                  │\n"; // 7y
    std::wcout << L" │ [E] Exit                            │\n"; // 8y
    std::wcout << L" └─────────────────────────────────────┘\n"; // 9y
    std::wcout << L" ┌─────────────────────────────────────┐\n"; // 10y
    std::wcout << L" │ Command:                            │\n"; // 11y
    std::wcout << L" └─────────────────────────────────────┘\n"; // 12y

    gotoxy(12, 11);
    std::getline(std::cin, command);

    // convert the command to uppercase;
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);
    
    // reset to the default utf, which is 8 bit unicode(ASCII is only 7 bits)
    _setmode(_fileno(stdout), _O_TEXT);

    return command;
}

std::string UserInterface::manageContactMenuInput()
{
    _setmode(_fileno(stdout), _O_U8TEXT);

    std::string command;
    std::wcout << L"\n";
    std::wcout << L" ┌─────────────────────────────────────┐\n";
    std::wcout << L" │       Contact Manager System        │\n";
    std::wcout << L" └─────────────────────────────────────┘\n";
    std::wcout << L" ┌─ Manage Contacts Menu ──────────────┐\n";
    std::wcout << L" │ [A] Add Contact                     │\n";
    std::wcout << L" │ [E] Edit Contact                    │\n";
    std::wcout << L" │ [D] Delete Contact                  │\n";
    std::wcout << L" │ [B] Back                            │\n";
    std::wcout << L" └─────────────────────────────────────┘\n";
    std::wcout << L" ┌─────────────────────────────────────┐\n";
    std::wcout << L" │ Command:                            │\n";
    std::wcout << L" └─────────────────────────────────────┘\n";
    
    gotoxy(12, 11);
    std::getline(std::cin, command);

    // convert the command to uppercase
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);

    _setmode(_fileno(stdout), _O_TEXT);

    return command;
}

// opions for viewing the contact list
std::string UserInterface::viewContactMenuInput()
{
    _setmode(_fileno(stdout), _O_U8TEXT);
    
    std::string command;
    std::wcout << L"\n";
    std::wcout << L" ┌─────────────────────────────────────┐\n"; 
    std::wcout << L" │       Contact Manager System        │\n";
    std::wcout << L" └─────────────────────────────────────┘\n";
    std::wcout << L" ┌─ View Contacts Menu ────────────────┐\n";
    std::wcout << L" │ [N] View By Name                    │\n";
    std::wcout << L" │ [P] View By Phone Number            │\n";
    std::wcout << L" │ [E] View By Email                   │\n";
    std::wcout << L" │ [B] Back                            │\n";
    std::wcout << L" └─────────────────────────────────────┘\n";
    std::wcout << L" ┌─────────────────────────────────────┐\n";
    std::wcout << L" │ Command:                            │\n";
    std::wcout << L" └─────────────────────────────────────┘\n";

    gotoxy(12, 11);
    std::getline(std::cin, command);

    // convert the command to uppercase
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);
    
    _setmode(_fileno(stdout), _O_TEXT);
    
    return command;
}

// options for searching the contact listb
std::string UserInterface::searchContactMenuInput()
{
    _setmode(_fileno(stdout), _O_U8TEXT);

    std::string command;
    std::wcout << L"\n";
    std::wcout << L" ┌─────────────────────────────────────┐\n"; // 1y
    std::wcout << L" │       Contact Manager System        │\n"; // 2y
    std::wcout << L" └─────────────────────────────────────┘\n"; // 3y
    std::wcout << L" ┌─ Search Contact Menu ───────────────┐\n";
    std::wcout << L" │ [N] Search By Name                  │\n";
    std::wcout << L" │ [P] Search By Phone Number          │\n";
    std::wcout << L" │ [E] Search By Email                 │\n";
    std::wcout << L" │ [K] Search By Keyword               │\n";
    std::wcout << L" │ [B] Back                            │\n";
    std::wcout << L" └─────────────────────────────────────┘\n";
    std::wcout << L" ┌─────────────────────────────────────┐\n";
    std::wcout << L" │ Command:                            │\n";
    std::wcout << L" └─────────────────────────────────────┘\n";

    gotoxy(12, 12);
    std::getline(std::cin, command);

    // convert the command to uppercase
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);

    _setmode(_fileno(stdout), _O_TEXT);

    return command;
}

// display contacts
void UserInterface::displayContacts(const std::vector<Contact>& contactList, int displayType)
{
    /* displayType
    *  Values: default 0
    *  0 =  viewing
    *  1 =  multiple search
    *  2 = single search
    */

    system("cls"); // clears the console

    std::string title, empty;
    if (displayType == 0)
    {
        title = "CONTACT LIST ";                   // prompt for the title of the table 
        empty = "No Recorded Contacts...";         // prompt when the contacts is empty
    }
    else 
    {
        title = "SEARCH RESULT";                  
        empty = "No Results Found...    ";   
    }

    _setmode(_fileno(stdout), _O_U8TEXT);

    // convert c++ tring to a wstring(wide string), 
    // to print it using wcout which prints wide unicode characters(16 bit in this case)
    std::wstring wTitle(title.begin(), title.end());
    std::wstring wEmpty(empty.begin(), empty.end());

    
    std::wcout << L"\n";
    std::wcout << L" ┌─ " << wTitle << L" ──────────────┬──────────────────────────────┬──────────────────────────────────────────┐\n";
    std::wcout << L" │             Name             │       Telephone Number       │                  Email                   │\n";
    std::wcout << L" └──────────────────────────────┴──────────────────────────────┴──────────────────────────────────────────┘\n";

    if (contactList.empty()) 
    {
        std::wcout << L" ┌────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n";
        std::wcout << L" │ " << wEmpty << L"                                                                                │\n";
        std::wcout << L" ├────────────────────────────────────────────────────────────────────────────────────────────────────────┤\n";
        std::wcout << L" └────────────────────────────────────────────────────────────────────────────────────────────── matthew ─┘\n";
    } 
    else 
    {
        std::wcout << L" ┌──────────────────────────────┬──────────────────────────────┬──────────────────────────────────────────┐\n";
        for (auto contact : contactList)
        {
            // convert string to wstring to print it using wcout
            std::wstring wName(contact.getName().begin(), contact.getName().end());
            std::wstring wPhonenumber(contact.getPhonenumber().begin(), contact.getPhonenumber().end());
            std::wstring wEmail(contact.getEmail().begin(), contact.getEmail().end());

            // Formatting for the attributes of contact
            // ensure that all will have the same spaces regardless of the size of the string
            std::wcout << L" │  " << std::setw(28) << std::left << wName
                      << L"│  " << std::setw(28) << std::left << wPhonenumber
                      << L"│  " << std::setw(40) << std::left << wEmail
                      << L"│ \n";
            std::wcout << L" ├──────────────────────────────┼──────────────────────────────┼──────────────────────────────────────────┤\n";
        }
        std::wcout << L" └──────────────────────────────┴──────────────────────────────┴──────────────────────────────── matthew ─┘\n";

    }

    std::wcout << "  "; // for system pause to have so space
    _setmode(_fileno(stdout), _O_TEXT);

    
    
    char exit_ch;
    std::cout << " Press 'r' to return...";

    // user needs to input x || X to exit the current function
    // I just thinking of putting a help button where if the user press ? it will show the help tab hehe...
    while (true)
    {
        exit_ch = getch();
        std::transform(&exit_ch, &exit_ch + 1, &exit_ch, ::tolower); // make input lowercase
        if (exit_ch == 'r') { break; }
    }

}

// i'm thinking of adding a parameter text so that it can be used with customized text
void UserInterface::warningMessage() // warning message for invalid menu options
{
    _setmode(_fileno(stdout), _O_U8TEXT);

    std::wcout << L"\n\n";
    std::wcout << L" ┌─ Warning ─────────────────┐\n";
    std::wcout << L" │      Invalid Command      │\n";
    std::wcout << L" └───────────────────────────┘\n";
    std::wcout << "  "; 
    system("pause");
    

    _setmode(_fileno(stdout), _O_TEXT);
}

// for manipulation in clearing certain lines in the terminal
void UserInterface::clearLines(const int& startLine, const int& numLines)
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

void UserInterface::gotoxy(const short int& x, const short int& y)
{
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
