#include <iostream>
using namespace std;
int main (){
    int a;
    cin >> a;
    int *arr=new int[a];

    for(int i=0;i<3;i++){
        cin >> arr[i];
    }
     for(int i=0;i<3;i++){
        cout << arr[i];
    }

}