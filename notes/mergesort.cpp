#include <iostream>
#include <vector>

void merge(std::vector<int>& leftArray, std::vector<int>& rightArray, std::vector<int>& array) {
    int leftSize = array.size() / 2;
    int rightSize = array.size() - leftSize;

    int i = 0, l = 0, r = 0; // indices
    

    while (l < leftSize && r < rightSize) {
        if (leftArray[l] < rightArray[r]) {
            array[i] = leftArray[l];
            i++;
            l++;
        }
        else {
            array[i] =  rightArray[r];
            i++;
            r++;
        }
    }

    while (l < leftSize) {
        array[i] = leftArray[l];
        i++;
        l++;
    }
    while (r < rightSize) {
        array[i] = rightArray[r];
        i++;
        r++;
    }
}

void mergeSort(std::vector<int>& array) {
    int length = array.size();
    if (length <= 1) return; // base case
    
    int middle = length / 2;
    std::vector<int> leftArray;
    std::vector<int> rightArray;

    int i = 0; // left array
    int j = 0; // right array
    
    for (; i < length; i++) {
        if (i < middle) {
            leftArray.push_back(array[i]);
        } else {
            rightArray.push_back(array[i]);
            j++;
        }
    }

    mergeSort(leftArray);
    mergeSort(rightArray);
    merge(leftArray, rightArray, array);

}


int main() {
    std::vector<int> array = {4, 5, 7, 8, 9, 0};

    std::cout << "Before sorting\n";
    for (int elem : array) {
        std::cout << elem << std::endl;
    }

    mergeSort(array);

    std::cout << "After sorting\n";
    for (int elem : array) {
        std::cout << elem << std::endl;
    }
    return 0;
}
