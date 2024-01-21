#include <iostream>
#include <windows.h>
#include <conio.h>

void gotoxy(short int x, short int y)
{
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

int main()
{
    int age;
    std::string name;
    std::cout << "Name: \n";
    std::cout << "Age: ";

    gotoxy(6, 1);
    std::cin >> name;

    gotoxy(5, 2);
    std::cin >> age;

    return 0;
}
