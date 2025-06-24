#include <iostream>
using namespace std;
class myclass{
    public:

    int age;
    int number;
    static int game;

};
int myclass ::game=7;

int main() {
    myclass h1;

    cout<< myclass ::game << endl;
    
}