#include <iostream>
using namespace std;
int main()
{

    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int col = 3;
    int row = 3;

    int total = col * row;
    int startcol = 0;
    int startrow = 0;
    int endcol = col - 1;
    int endrow = row - 1;
    int count = 0;
    while (count < total)
    {
        for (int index =  startcol; count < total && index <= endcol; index++)
        {
            cout << arr[startrow][index] << " ";
            count++;
        }
        startrow++;
        for (int index =  startrow; count < total && index <= endrow; index++)
        {
            cout << arr[index][endcol] << " ";
            count++;
        }
        endcol--;
        for (int index = endcol; count < total && index >= startcol; index--)
        {
            cout << arr[endrow][index] << " ";
            count++;
        }
        endrow--;
        for (int index = endrow; count < total && index >=  startrow; index--)
        {
            cout << arr[index][startcol] << " ";
            count++;
        }
        startcol++;
    }
}