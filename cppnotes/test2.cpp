#include <iostream>

class Calculator {
public:
    // Member function to add two numbers
    int add(int a, int b) {
        return a + b;
    }

    // Member function to subtract two numbers
    int subtract(int a, int b) {
        return a - b;
    }

    // Function pointer type definition
    using OperationFunction = int (Calculator::*)(int, int);

    // Member function to perform a selected operation using the function pointer
    int performOperation(int a, int b, OperationFunction operation) {
        return (this->*operation)(a, b);
    }
};

int main() {
    Calculator calculator;

    char choice;
    std::cout << "Enter 'a' for addition, 's' for subtraction: ";
    std::cin >> choice;

    // Define a pointer to member function
    Calculator::OperationFunction operation;

    if (choice == 'a') {
        operation = &Calculator::add;
    } else if (choice == 's') {
        operation = &Calculator::subtract;
    } else {
        std::cout << "Invalid choice." << std::endl;
        return 1;
    }

    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;

    // Use the function pointer to call the selected member function
    int result = calculator.performOperation(x, y, operation);

    std::cout << "Result: " << result << std::endl;

    return 0;
}

