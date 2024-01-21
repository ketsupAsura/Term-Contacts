#include <iostream>
#include <vector>

int binarySearch(int array[], int target, int size) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int middle = low + (high - low) / 2;
        int value = array[middle];

        std::cout << "middle: " << value << "\n";

        // each iteration the binary search adjusts the low and high indxes of the array
        if (value < target) { low = middle + 1; }
        else if (value > target) { high = middle - 1; }
        else return middle; // target is found
    }

    return -1;
}

int main() {
    int size = 2;
    int array[2];
    int target = 1;

    for (int i = 0; i < size; i++) {
        array[i] = i;
    }

    int index = binarySearch(array, target, size);

    if (index != -1) {
        std::cout << "Target found at index: " << index << "\n";
    } 
    else {
        std::cout << "Element not found\n"; 
    }

    return 0;
}


