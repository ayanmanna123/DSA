#include <iostream>
using namespace std;
int main()
{
    int arr[3][3] = {7,  6, 3, 8, 5,  4, 9, 1, 9};
    

    for (int k = 0; k < 3; k++)
    {

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                if (arr[k][j] > arr[k][j + 1])
                {

                    int tem = arr[k][j];
                    arr[k][j] = arr[k][j + 1];
                    arr[k][j + 1] = tem;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int k = 0; k < 3; k++)
    {

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                if (arr[j][k] > arr[j + 1][k])
                {

                    int tem = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = tem;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}