#include <iostream>
using namespace std;
int function(int& a){
    a++;
}
int main (){
    int i=5;
    // int& j=i;
    // i++;
    // cout << i << endl;
    // j++;
    // cout << i <<endl;
    function(i);
    cout << i << endl;
}