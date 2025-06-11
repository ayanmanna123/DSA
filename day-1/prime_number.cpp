#include <iostream>
using namespace std;
int main()
{
    cout << "ent a number" << endl;
    int num;
    cin >> num;
    int tem = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            tem++;
        }
    }
    if (tem == 2)
    {
        cout << "number is prime number" << endl;
    }
    else
    {
        cout << "number is not prime number " << endl;
    }
}