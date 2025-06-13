#include <iostream>
using namespace std;
void swape(int arr[], int a, int b)
{
    int temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int main()
{

    int arr[6] = {1, 2, 0, 16, 64, 9};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swape(arr, j, j + 1);
            }
        }
    }

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}