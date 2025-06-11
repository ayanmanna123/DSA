#include <iostream>
using namespace std ;
int main(){
    int n;
    cin>> n;
    int num =0;
    while(n!=0){
        int dig=n%2;
        num=(num*10)+dig;
        n=n/2;

    }

    while(num!=0){
        int dig=num%10;
        int Not=~dig;
        cout << Not <<endl ;
        num=num/10;

    }
    cout << num << endl;
}