#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=10;
     long long first=0;
     long long sec=1;
     long long fib=0;
    cout<<first << " "  ;
     cout<<sec << " "  ;
    for(int i=2;i<n;i++){
        fib=(first + sec);
        first=sec;
        sec=fib; 
         cout<< fib<<" ";

    }
   
}