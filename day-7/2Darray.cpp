#include <iostream>
using namespace std;
int main (){

    int a;
    cin >> a;
    int **arr=new int *[a];
    for(int i=0;i<a;i++){

        arr[i]=new int[a];
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cout <<  arr[i][j];
        }
        cout << endl;
    }
}