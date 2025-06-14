#include <iostream>
using namespace std;
int main()
{
    char arr[] = {'a', 'a', 'a', 'b', 'b', 'c'};
    char tem[6];
    int k=0;
    for (int i = 0; i < sizeof(arr); i++)
    {
        int count = 0;
        for (int j = i + 1; j < sizeof(arr); j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                i++;
                
            }
        }
        tem[k] = arr[i];
        k++;
        if (count != 0)
        {
            string s = to_string(count);
            for (char ch : s) {
                tem[k++] = ch;
            }
        }
    }
    for (int i = 0; i < sizeof(tem); i++)
    {
        cout << tem[i] << " ";
    }
}