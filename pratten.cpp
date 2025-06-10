#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 0;
    int tem = 1;
    while (i < n)
    {
        int j = 65 + n ;
        while (j <= i + 65 + n)
        {
            char tem = j-i-1;
            cout << tem;

            j++;
        }
        cout << endl;
        i++;
    }
}
