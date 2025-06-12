#include <iostream>
using namespace std;
int main(){
  int arr[3]={1,2,3}, ar[2]={3,4};
  for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
        if(arr[i]==ar[j]){
            cout << arr[i];
        }
    }
  }
}