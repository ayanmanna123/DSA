#include <iostream>
using namespace std;

void merge(int array[], int left, int middle, int right) {
    int sizeLeft = middle - left + 1;
    int sizeRight = right - middle;

    int leftArray[sizeLeft], rightArray[sizeRight];

    // Copy data to temporary arrays
    for (int i = 0; i < sizeLeft; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < sizeRight; j++)
        rightArray[j] = array[middle + 1 + j];

    // Merge the temporary arrays back into the original array
    int indexLeft = 0, indexRight = 0, indexMerged = left;

    while (indexLeft < sizeLeft && indexRight < sizeRight) {
        if (leftArray[indexLeft] <= rightArray[indexRight]) {
            array[indexMerged++] = leftArray[indexLeft++];
        } else {
            array[indexMerged++] = rightArray[indexRight++];
        }
    }

    // Copy any remaining elements
    while (indexLeft < sizeLeft)
        array[indexMerged++] = leftArray[indexLeft++];

    while (indexRight < sizeRight)
        array[indexMerged++] = rightArray[indexRight++];
}

void mergeSort(int array[], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;

        mergeSort(array, start, middle);        // Sort first half
        mergeSort(array, middle + 1, end);      // Sort second half
        merge(array, start, middle, end);       // Merge both halves
    }
}

// Example usage
int main() {
    int numbers[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    mergeSort(numbers, 0, size - 1);

    // Print sorted array
    for (int i = 0; i < size; i++)
        cout << numbers[i] << " ";

    return 0;
}
