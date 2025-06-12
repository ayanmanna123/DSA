#include <iostream>
using namespace std;

bool ispossible(int arr[], int n, int m, int mid)
{
    int studentcount = 1;
    int pagesum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pagesum + arr[i] <= mid)
        {
            pagesum += arr[i];
        }
        else
        {
            studentcount++;
            if (studentcount > m || arr[i] > mid)
            {
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}

int main()
{
    int s = 0;
    int sum = 0;
    int n = 6;
    int arr[n] = {10, 20, 30, 40, 50, 60};
    int m = 2;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int e = sum;
    int ans;
    int mid = (s + e) / 2;

    while (s <= e)
    {
        if (ispossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = (s + e) / 2;
    }

    cout << "Minimum possible maximum pages = " << ans << endl;
    return 0;
}
