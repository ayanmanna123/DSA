#include <iostream>
using namespace std;
int main (){
    int arr[5]={1,5,0,3,0};
    int k=0;
    for(int i=0;i<5;i++){
        if(arr[i]!=0){
            int tem=arr[i];
            arr[i]=arr[k];
            arr[k]=tem;
            k++;
             
        }
    }
    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }
}