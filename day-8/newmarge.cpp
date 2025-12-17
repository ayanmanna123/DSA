#include <bits/stdc++.h>
using namespace std;

void marge(vector<int> &arr, int s, int e, int mid)
{

    vector<int> temp;
    int i = s;
    int j = mid + 1;

    while (i <= mid && j <= e)
    {

        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= e)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[s + i] = temp[i];
    }
}

void margesort(vector<int> &arr, int s, int e)
{

    if (s >= e)
        return;

    int mid = (s + e) / 2;
    margesort(arr, s, mid);
    margesort(arr, mid + 1, e);

    marge(arr, s, e, mid);
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1, 6};
    margesort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        cout << " ";
    }
}