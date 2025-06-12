#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter no of element" << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter" << i << "no of element" << endl;
        cin >> arr[i];
    }
    int sc;
    cout << "enter scarch number" << endl;
    cin >> sc;
    int min = 0;
    int max = n;

    for (int i = 0; i<n; i++)
    {
        if (max >= min)
        {
            int mid = (min + max) / 2;
            if (arr[mid] == sc)
            {
                cout << mid;
                break;
            }
            else if (arr[mid] < sc)
            {
                min = mid + 1;
            }
            else if (arr[mid] > sc)
            {
                max = mid - 1;
            }
        }

        else
        {
            cout << "mot aviblable" << endl;
            break;
        }
    }
}