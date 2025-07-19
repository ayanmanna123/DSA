#include <bits/stdc++.h>
using namespace std;
int fib(int n, int arr[]) {
     if(n==0 || n==1){
        return n;
     }
     if(arr[n]!= -1){
        return arr[n];
     }
     arr[n]=fib(n-1,arr) + fib(n-2,arr);

    return arr[n];
}
int main() {
    int n=7;
    int arr[n+1];

    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
    cout << fib(n,arr);
}