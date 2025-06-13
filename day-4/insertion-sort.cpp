#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {3, 5, 2, 8, 6, 9};

    for(int i = 1; i < 6; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " "; 
    }
}
