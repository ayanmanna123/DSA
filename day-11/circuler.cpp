#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }

     ~Node() {
        int val = this->data;
        if (this->next != NULL) {
            delete this->next;
            this->next = NULL;
        }
        cout << "Memory freed for node with data: " << val << endl;
    }
};


void insertNode(Node*& tail, int element, int data) {
     
    if (tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;   
        return;
    }

    
    Node* curr = tail;

    do {
        if (curr->data == element) {
            Node* newNode = new Node(data);
            newNode->next = curr->next;
            curr->next = newNode;

             
            if (curr == tail) {
                tail = newNode;
            }
            return;
        }
        curr = curr->next;
    } while (curr != tail);

    cout << "Element " << element << " not found in the list." << endl;
}

 
void printList(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

void deleteNode(Node*& tail, int position) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* prev = tail;
    Node* curr = prev->next;

    
    if (position == 1) {
        while (prev->next != tail->next) {
            prev = prev->next;
        }

        if (prev == curr) {
            tail = NULL;  
        } else {
            prev->next = curr->next;
            if (curr == tail) tail = prev;
        }

        curr->next = NULL;
        delete curr;
        return;
    }

    
    int count = 1;
    while (count < position && curr->next != tail->next) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (count != position) {
        cout << "Position out of bounds" << endl;
        return;
    }

    prev->next = curr->next;
    if (curr == tail)
        tail = prev;

    curr->next = NULL;
    delete curr;
}

// Demo
int main() {
    Node* tail = NULL;

    insertNode(tail, 0, 10);
    printList(tail);   

    insertNode(tail, 10, 20);
    printList(tail); 

    insertNode(tail, 20, 30);
    printList(tail); 

    insertNode(tail, 30, 40);
    printList(tail); 

    insertNode(tail, 40, 27); 
    printList(tail); 

    deleteNode(tail,1);  
    printList(tail); 

    
}
