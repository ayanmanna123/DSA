#include <iostream>
using namespace std;
int main (){
    int arr[5]={1,2,3,4,3};
    int xorAll = 0;
    int n = 5;

    // XOR all array elements
    for (int i = 0; i < n; i++) {
        xorAll ^= arr[i];
    }

    // XOR with numbers from 1 to N-1
    for (int i = 1; i < n; i++) {
        xorAll ^= i;
    }

    cout << xorAll <<endl;
	
}