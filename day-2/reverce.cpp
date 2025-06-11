#include <iostream>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int num = 0;
    int i = 0;
    if (n >= INT32_MAX && INT32_MIN>=n)
    {

        num = 0;
    }
    else
    {
        while (n != 0)
        {
            int digit = n % 10;
            num = (num * 10) + digit;
            n = n / 10;
        }
    }

    cout << num << endl;
}