#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data= data;
        this->next=NULL;
    }
};
void insertathead(node* & head , int d){
    node * temp = new node(d);
    temp->next=head;
    head=temp;
}
void insertattell(node* tell , int d){
    node* temp= new node(d);
    tell->next=temp;
    tell= tell->next;
}
void print(node * &head){
    node * temp= head;
    while(temp!= NULL){
        cout<< temp->data <<" ";
        temp=temp->next;
    }
}
int main() {
    node* node1= new node(4);
    node * head = node1;
    node * tell = node1;
    insertathead(head , 8);
    insertattell(tell , 5);
    print(head);
     
}