#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int data){
        this->data =data;
        this->next=NULL;
        this->prev=NULL;

    }
};
void insertathead(node* &head ,int data){
    node* temp=new node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void instrtattell(node* &tell, int data){
    node* temp= new node(data);
    tell->next= temp;
    temp->prev=tell;
    tell=temp;
}
void insertanywhere(node* &head , node* &tell , int d, int position){
    if(position==1){
        insertathead(head , d);
        return;
    }
    node* temp= head;
    int c=1;
    while(position>c){
        temp= temp->next;
        c++;
    }
    if(temp->next == NULL){
        instrtattell(tell , d);
        return;
    }
  
    node* setnode = new node(d);
     setnode->next=temp->next;
     temp->next->prev=setnode;
     setnode->prev=temp;
     temp->next=setnode;

}
void print(node* &head){
    node* temp= head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() {
    node* node1=new node(6);
    node* head= node1;
    node* tell=node1;
    insertathead( head ,9);
    instrtattell(tell ,0);
    insertanywhere(head , tell , 5, 3);
    print(head);
}