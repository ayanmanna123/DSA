#include <iostream>
using namespace std;
bool binary(int arr[] , int s , int e, int key){

     if(s>e){
        return false;
     }
     int mid=(s+e)/2;
     if(arr[mid]==key){
        return true;
     }
     if(arr[mid]<key){
        binary(arr ,  mid+1 ,  e, key);
     }
     else{
        binary(arr, s, mid-1, key);
     }

     
     

}
int main() {
    int arr[6]={1,2,3,4,5,6};
    int key =7;
    int s=0;
    int e=6;


   cout<<  binary(arr, s , e, key);
}