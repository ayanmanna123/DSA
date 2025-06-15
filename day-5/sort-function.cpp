#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[3][3] = {7,  6, 3, 8, 5,  4, 9, 1, 9};
    int arr1[6]={7,  6, 3, 8, 5,  4};
    int row=3;
//     for(int i=0;i<3;i++){
//          sort(arr[i], arr[i] + 3);
         
//     }
//      for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
    // Sort the entire arr1 array
    sort(arr1, arr1 + 6);
    // Print the sorted array
    for (int i = 0; i < 6; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
 }