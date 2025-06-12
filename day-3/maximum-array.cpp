#include <iostream>
using namespace std;
int main(){
    int arr[7]={5,6,4,8,6,-7,-4};
    int tem=arr[1];
    int max;
    for(int i=0;i<7;i++){
        if(tem>=arr[i]){
            tem=arr[i];
        }

    }
    cout<< tem << endl;

}