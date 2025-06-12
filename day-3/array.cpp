#include <iostream>
using namespace std;
int main(){
    int arr[7]={1,2,3,4,5,6,7};
    int n=7;
    int t=n;
    int tem;
    int k=n/2;
    for(int i=0;i<3;i++){

       tem=arr[n-1];
       arr[n-1]=arr[i];
       arr[i]=tem;
       n=n-1;

    }
     for(int i=0;i<t;i++){
        cout<< arr[i] ;
     }
}