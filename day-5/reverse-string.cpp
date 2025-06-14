#include <iostream>
using namespace std ;
int main(){
    char arr[5] = {'a',' ','c','d','e'};
    int n=4;

    for(int i=0;i<n;i++){

        char tem = arr[i];
        arr[i]=arr[n];
        arr[n]=tem;
        n--;
    }
     for(int i = 0; i < 5; i++) 
    {
        cout << arr[i] << " "; 
    }


}