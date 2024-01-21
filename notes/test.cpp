#include <iostream>
#include <string>

class What {
public:
    std::string name = "Matt Rohan alagaban";
};

int main() {
    What what = What();
    std::string name = "Matt rohan alagaban";
    std::string input;

    std::cout << "Enter a substring: ";
    std::getline(std::cin, input);

    // .find method returns the position of the first ocurrence of the substring in a string
    // if the .find doesn't find the substring in the string it will return a std::string::npos value

    if (name.find(input) != std::string::npos){
        std::cout << "Name Found: " << name << "\n";
    }

    if (what.name.find(input) != std::string::npos) {
        std::cout << "Name Found: " << name << "\n";
    }

    int low = 1;
    int high = 100;
    std::cout << low + (high - low) / 2 << std::endl;

    std::cout << (high + low) / 2 << std::endl;

    return 0;
}
