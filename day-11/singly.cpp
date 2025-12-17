#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "free ho cuka hai" << value << endl;
    }
};
void insertathead(node *&head, int d)
{
    node *tem = new node(d);
    tem->next = head;
    head = tem;
}

void inserttall(node *&tall, int d)
{
    node *tem = new node(d);
    tall->next = tem;
    tall = tem;
}
void insertanyhear(node *&head, int position, int d, node *&tall)
{
    if (position == 0)
    {
        insertathead(head, d);
        return;
    }

    node *tem = head;
    int cunt = 0;
    while (cunt < position - 1)
    {
        tem = tem->next;
        cunt++;
    }
    if (tem->next == NULL)
    {
        inserttall(tall, d);
        return;
    }
    node *nodetoinsert = new node(d);
    nodetoinsert->next = tem->next;
    tem->next = nodetoinsert;
}
void deletnode(int position, node *&head)
{
    if (position == 0)
    {
        node *tem = head;
        head = head->next;
        tem->next = NULL;
        delete tem;
    }
    else
    {
        node *current = head;
        node *prev = NULL;
        int count = 0;
        while (count < position)
        {
            prev = current;
            current = current->next;
            count++;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}
void print(node *&head)
{
    node *tem = head;
    while (tem != NULL)
    {
        cout << tem->data << " ";
        tem = tem->next;
    }
    cout << endl;
}

int main()
{
    node *node1 = new node(10);
    // cout << node1->data <<endl;
    // cout << node1->next <<endl;
    node *head = node1;
    node *tall = node1;
    // int position = 4;
    // print(head);
    // insertathead(head, 7);
    inserttall(tall, 12);
    print(head);
    inserttall(tall, 13);
    print(head);
    inserttall(tall, 17);
    print(head);
    // insertanyhear(head, position, 34, tall);
    // print(head);
    // deletnode(3, head);
    // print(head);
    // cout << head->data << endl;
    // cout << tall->data << endl;
}