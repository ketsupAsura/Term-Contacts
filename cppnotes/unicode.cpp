#include <iostream>

// _setmode, _fileno, which set the mode of the file stdout to handle the specified unicode
#include <io.h>  // input/output related functions

// this set the mode of the stdout stream to handle unicode text (_O_U16TEXT)
#include <fcntl.h> // file control operations

int main()
{
    std::cout << "Hello\n";
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::cout << "world\n";
    std::wcout << L"┌──────────────┐\n";
    std::wcout << L"│              │\n";
    std::wcout << L"└──────────────┘\n";
    system("pause");
    system("cls");
    std::wcout << L"┌─ Contact List ─────────────────┐\n";
    std::wcout << L"│        This is awesome!        │\n";
    std::wcout << L"└────────────────────────────────┘\n";

    // this reset the utf to the default text mode
    // so we can use std::cout again
    _setmode(_fileno(stdout), _O_TEXT); 
    return 0;
}
/*#include <iostream>
#include <io.h>
#include <fcntl.h>

int main() {
    // Set the console to support Unicode
    _setmode(_fileno(stdout), _O_U16TEXT);

    // Print the horizontal line "─"
    std::wcout << L"─\n";

    // Reset the console mode to the default
   // _setmode(_fileno(stdout), _O_TEXT);

    return 0;
}*/
