#include <iostream>
using namespace std;
int main()
{
    cout << "enter a alphabet " << endl;
    char num;
    cin >> num;
    int num1 = num;
    if (num1 >= 65 && num1 <= 90)
    {
        cout << "alphabat is capital " << endl;
    }
    else if (num1 >= 97 && num1 <= 122)
    {
        cout << "alphabat is small " << endl;
    }
    else
    {
        cout << "character" << endl;
    }
}