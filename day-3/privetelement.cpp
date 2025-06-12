#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {7, 9, 1, 2, 3};
    int max = 5, min = 0;
    int mid = (max + min) / 2;
     while (max>min){

        if (arr[mid] > arr[min])
        {
            min = mid + 1;

        }
        else {
            max=mid;
             
        }
         mid = (max + min) / 2;
    }
    cout << min <<endl;
}