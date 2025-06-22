#include <iostream>
using namespace std;

// Swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition using first element as pivot
int partition(int array[], int start, int end) {
    int pivot = array[start];
    int i = start + 1;
    int j = end;

    while (i <= j) {
        // Move i to the right until an element >= pivot
        while (i <= end && array[i] <= pivot) i++;
        // Move j to the left until an element < pivot
        while (array[j] > pivot) j--;

        if (i < j) {
            swap(array[i], array[j]);
        }
    }

    // Place pivot in the correct position
    swap(array[start], array[j]);
    return j; // Pivot's final position
}

// Quick Sort recursive function
void quickSort(int array[], int start, int end) {
    if (start < end) {
        int pivotIndex = partition(array, start, end);
        quickSort(array, start, pivotIndex - 1); // Sort left part
        quickSort(array, pivotIndex + 1, end);   // Sort right part
    }
}

// Main function
int main() {
    int numbers[] = {24, 9, 29, 14, 19, 27};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    quickSort(numbers, 0, size - 1);

    // Print sorted array
    for (int i = 0; i < size; i++)
        cout << numbers[i] << " ";

    return 0;
}
