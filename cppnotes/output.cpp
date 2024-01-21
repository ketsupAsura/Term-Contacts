#include <iostream>
#include <windows.h>

void clearLines(int startLine, int numLines) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the cursor position to the start of the specified line
    COORD coord;
    coord.X = 0;
    coord.Y = startLine;
    SetConsoleCursorPosition(hConsole, coord);

    // Fill the specified number of lines with spaces
    for (int i = 0; i < numLines; ++i) {
        DWORD written;
        FillConsoleOutputCharacter(hConsole, ' ', 80, coord, &written);  // Assuming 80 columns
        FillConsoleOutputAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, 80, coord, &written);  // Reset attributes
        coord.Y++;
    }
}

int main() {
    std::cout << "This is line 1.\n";
    std::cout << "This is line 2.\n";
    std::cout << "This is line 3.\n";
    system("pause");

    // Clear lines 2 and 3
    clearLines(2, 3);

    system("pause");

    std::cout << "This is line 1.\n";
    std::cout << "This is line 2.\n";
    std::cout << "This is line 3.\n";

    system("pause");

    return 0;
}

