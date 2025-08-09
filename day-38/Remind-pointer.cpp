#include <bits/stdc++.h>
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
};
void insertathead(node *&head, int d)
{
    node *tem = new node(d);
    tem->next = head;
    head = tem;
}
void insertattell(node *&tell, int d)
{
    node *temp = new node(d);
    tell->next = temp;
    tell = tell->next;
}
void insertanywhere(node *&head, node *&tell, int position, int d)
{
    if (position == 0)
    {
        insertathead(head, d);
    }
    int count = 0;
    node *temp = head;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    node *add = new node(d);

    if (temp->next == NULL)
    {
        insertattell(tell, d);
    }
    add->next = temp->next;
    temp->next = add;
}
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    node *node1 = new node(8);
    node *head = node1;
    node *tell = node1;
    insertathead(head, 3);
    insertattell(tell, 4);
    insertanywhere(head, tell, 2, 9);
    print(head);
}