#include <iostream>
using namespace std;
class node{
public:
    int data;
    node* prev;
    node* next;
    node(int d){
        this-> data=d;
        this-> prev=NULL;
        this -> next=NULL;
    }

};

void print (node * head){
    node* tem=head;
    while(tem!= NULL){
        cout << tem->data <<" ";
        tem=tem->next;
    }
    cout << endl;

}
int length (node * head){
    node* tem=head;
    int count=0;
    while(tem!= NULL){
         count ++;
        tem=tem->next;
    }
    return count;

}
void insertathead(int d, node * &head){
    node* tem=new node(d);
    tem->next=head;
    head->prev=tem;
    head=tem;
}
void insertattail(int d, node* &tail){

    node* tem=new node(d);
    tail->next=tem;
    tem->prev=tail;
    tail=tem;
}
void insertanywhere(node* &head, node* &tail, int d, int position){
     if(position==0){
        insertathead(d,head);
        return;
    }
    node* tem=head;
    int cunt=0;
    while(cunt < position-1){
        tem=tem->next;
        cunt ++;

    }
       
    if(tem-> next ==NULL){
        insertattail(d,tail);
        return;
        
    }
     node * nodetoinsert=new node(d);
     nodetoinsert->next=tem->next;
     tem->next->prev=nodetoinsert;
     tem->next=nodetoinsert;
     nodetoinsert->prev=tem;



}

int main() {
     node* node1=new node(10);
     node * head= node1;
     node* tail=node1;
     int position=3;
     print(head);
    //  cout << endl;
    //  cout << length(head) << endl;
    insertathead(12,head);
    print(head);
    insertattail(33,tail);
    print(head);
    insertanywhere(head,tail,56,position);
    print(head);


}