#include <iostream>
#include <string>

int main() {
    // Create a standard string
    std::string narrowString = "Hello, World!";

    // Convert the standard string to a wide string
    std::wstring wideString(narrowString.begin(), narrowString.end());

    // Print the wide string using wcout
    std::wcout << wideString << std::endl;

    return 0;
}

