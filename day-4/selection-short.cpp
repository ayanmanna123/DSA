#include <iostream>
using namespace std;
void swape(int arr[],int a,int b){
    int temp;
    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;

}
int main(){
    int arr[5]={2,4,1,6,7};
    for(int i=0;i<4;i++){
          int mid=i;
        for(int j=i+1;j<4;j++){
            if(arr[mid]>arr[j]){
                mid=j;
            }

        }
        swape(arr,i,mid);

    }
    for(int i=0;i<5;i++){
        cout << arr[i]<<" ";
    }
}