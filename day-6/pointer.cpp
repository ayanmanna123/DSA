#include <iostream>
using namespace std;
 void printnumber(int *a){
     
     a=a+1;
 }
int main()
{

    int a = 9;
    int *ptr = &a;
    int **ptr1 = &ptr;
    // cout << *ptr << endl;
    // cout << ptr << endl;
    // cout << *ptr << endl;
    // cout << ++(*ptr) << endl;
    // cout << a << endl;

    // cout << a << endl;
    // cout << ptr << endl;
    // cout << *ptr << endl;
    // cout << ptr1 << endl;
    // cout << **ptr1 << endl;
    // cout << &ptr1 << endl;
     

    printnumber(ptr);
    cout << *ptr << endl;
    cout << a << endl;




}