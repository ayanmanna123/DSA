#include <iostream>
using namespace std;
int fac(int a){
    if(a==0){
        return 1;
    }
    int chota=fac(a-1);
    int fac=(a) * chota;
    return fac;

}
int main (){
    int a=6;
   cout <<  fac(a);
}