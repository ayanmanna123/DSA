#include <bits/stdc++.h>
using namespace std;

int main()
{
    string temp;
    string word = " ";
    for (int i = 0; i < word.length(); i++)
    {
     char nextChar;
        if (word[i] == 'z')
        {
            nextChar = 'a';
        }
        else{
            nextChar = word[i] + 1;
        }
         
        temp = temp + nextChar;
    }
    cout << temp << endl;
    string new1= "abc";
    string new2= "abc";
    cout << new1+new2 << endl;
}