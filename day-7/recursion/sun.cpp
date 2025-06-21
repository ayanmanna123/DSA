#include <iostream>
using namespace std;
int fun(int a){
   
    if(a==0){
        return 0;
    }
    int sum=a+fun(a-1);
    return sum;
}
int main (){
  
    int a=10;
    cout << fun(a);

}