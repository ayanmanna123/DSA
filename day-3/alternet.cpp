#include <iostream>
using namespace std;
int main (){
    int arr[7]={1,2,4,5,6,7,4};
    int tem;
    for (int i=0;i<7;i++){
        tem=arr[i+1];
        arr[i+1]=arr[i];
        arr[i]=tem;
        i++;
    }
    for(int i=0;i<7;i++){
        cout << arr[i] ;
    }
}