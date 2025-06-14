#include <iostream>
using namespace std;
int main()
{
    int arr1[5] = {2, 3, 6, 7, 18};
    int arr2[3] = {2, 3, 4};
    int tem[5];
    int n1 = 4;
    int n2 = 2;
    int k=0;
    for (int i = 4; i >= 0; i--)
    {
        if (n1 != -1 && n2 != -1)
        {
            tem[i] = arr1[n1] + arr2[n2] + k;
            k = 0;
            if (tem[i] > 9)
            {
                k = tem[i] / 10;
                tem[i] = tem[i] % 10;
            }
            n1--;
            n2--;

            // cout << "n1=>" << n1<< endl << "n2=>" << n2 << endl;
        }
        else if (n1 == -1)
        {
            tem[i] = arr2[n2] + k;
            if (tem[i] > 9)
            {
                k = tem[i] / 10;
                tem[i] = tem[i] % 10;
            }
            n2--;
        }
        else if (n2 == -1)
        {
            tem[i] = arr1[n1] + k;
            if (tem[i] > 9)
            {
                k = tem[i] / 10;
                tem[i] = tem[i] % 10;
            }
            n1--;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << tem[i] << " ";
    }
}