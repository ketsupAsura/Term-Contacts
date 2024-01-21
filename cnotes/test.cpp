#include <iostream>
#include <conio.h>

int main()
{
    char ch;
    std::cout << "Press any key: ";
    while (true)
    {
        ch = getch();
        if (ch == 'm') { break; }
    }

    return 0;
}
