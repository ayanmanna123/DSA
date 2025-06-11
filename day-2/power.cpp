#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    float div = n;
    while (div >= 1)
    {
        div = div / 2;
        if (div == 1)
        {
            cout << "power" << endl;
            return true;
            break;

        }
    }
    if (div != 1)
    {
       cout << "not power " <<endl;
       return false;
    }
}
