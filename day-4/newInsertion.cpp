#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {4, 2, 3, 1, 5};

    for (int i = 1; i < 5; i++)
    {
        int curr = arr[i];
        int j = i - 1;
        for (; j >=0 ; j--)
        {
            if (curr < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = curr;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        cout << " ";
    }
}