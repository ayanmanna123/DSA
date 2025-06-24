#include <iostream>
using namespace std;
class buity{

public:
    string name;
    int age;
    float height;

private:

     int copy ;
public:
     int printcopy(){

        cout << copy <<endl;

     }
     int setcopy(int copy){
        this->copy =copy;
     }


};

int main() {
    
 
    // buity h1;
    // buity h2;
    // h2=h1;
    // h1.name="ayan";
    // h2.height=12.4;
    // h2.height++;
    // cout << h1.name <<endl;
    // cout << h1.height <<endl;

    /// dynamacaly alocated variable

    // buity *b =new buity;
    // b->height=12.76;
    // delete b;
    // cout << b->height <<endl;
    // cout <<b->height <<endl;
    buity h2;
    h2.name="ayan";
    h2.height=12.4;
    
    buity h1(h2);
    h1.height=12;
    h1.setcopy(12);
    h1.printcopy();

    cout << h1.name <<endl;


}