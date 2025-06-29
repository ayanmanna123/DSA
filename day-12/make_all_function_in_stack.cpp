#include <bits/stdc++.h>
using namespace std;

class Stack{

    int *arr;
    int top;
    int size;
    public:
    Stack(int size){
        this->size=size;
        arr = new int[size];
        top=-1;
    }
    void push(int element){
         
        if(size-top >1){

            top++;
            arr[top]=element;

        }
        else{
            cout << "Stack is over flow" <<endl;
        }

    }
    void pop(){
        if(top> -1){
            top--;

        }
        else{
            cout << "Stack is empty" << endl;
        }
    }
    int pick(){
        if(top == -1){
              cout << "Stack is empty" << endl;
        }
        else{
            return arr[top];
        }
    }
    bool empty2(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {

    Stack st(3);
    st.push(1);
      st.push(2);
        st.push(3);
         st.pop();
        cout <<  st.pick() <<endl;
      cout << st.empty2() << endl;
    
}