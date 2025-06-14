#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {2, 3, 4, 5, 6};
    int k = 2;
    int j = 0;
    int temp[5];
    for (int i = 0; i < 5; i++)
    {
        int tem = arr[i];
        if (k < 5)
        {
            temp[k] = tem;

            cout << tem << endl;
            k++;
        }
        else
        {
            temp[j] = tem;
            j++;
            k++;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << temp[i] << "";
    }
}