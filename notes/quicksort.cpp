#include <iostream>

// sort the array and find the pivot
// helper function for the quicksort
int partition(int array[], int start, int end) {

    // pivot will start at the end of the array
    int pivot = array[end];

    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {

        // if the array[j] number is less than the pivot should be in the left side of the pivot 
        // if the array[j] number is greater than the pivot then it should be in the right side 
        if (array[j] < pivot) {
            i++;
             
            // swap i and j elements respectively
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // we add 1 since we want the pivot to be greater than the left of the array
    // and less than the right side of the array
    i++;

    // we are going to put the pivot at the right position
    // were its left side are the elements less than the pivot and 
    // the right side are the elements greater than the pivot
    int temp = array[i];
    array[i] = array[end];
    array[end] = temp;
    return i;
}

void quickSort(int array[], int start, int end) {
     
    if (end <= start) { return; } // base case
    
    // find the pivot (index of the end of the array in this implementation)
    int pivot = partition(array, start, end);

   
    /*// this will print the unsorted left partition
    std::cout << "unsorted left partition\n";
    for (int i = 0; i < 9; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n\n";
    */

    // left partition
    quickSort(array, start, pivot - 1);

    // this will print the sorted left partition
    std::cout << "sorted left partition\n";
    for (int i = 0; i < 9; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n\n";

    /*// this will print the unsorted right partition
    std::cout << "unsorted right partition\n";
    for (int i = 0; i < 9; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n\n";
    */

    // right partition
    quickSort(array, pivot + 1, end);

    // this will print the sorted right partition
    std::cout << "sorted right partition\n";
    for (int i = 0; i < 9; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n\n";
}

int main() {
    int array[] = {8, 2, 4, 7, 1, 3, 9, 6, 5};
    int length = 9;

    std::cout << "Original Array: ";
    for (int elem : array) {
        std::cout << elem << " ";
    }
    std::cout << "\n\n";

    // parameters:
    // array, beginning index, ending index
    quickSort(array, 0, length - 1);

    std::cout << "Final Array: ";
    for (int elem : array) {
        std::cout << elem << " ";
    }
}
