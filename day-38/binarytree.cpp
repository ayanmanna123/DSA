#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildtree(node *root)
{
    int data;
    cout << "enter data" << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);

    cout << "enter data for left side" << data << endl;
    root->left = buildtree(root->left);
    cout << "enter data for right side" << data << endl;
    root->right = buildtree(root->right);
    return root;
}
void levelordertrevle(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())

    {
        node *temp = q.front();

        q.pop();
        if (temp == NULL)
        {
            cout << endl;
             
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
             if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    node *root = buildtree(root);

    levelordertrevle(root);
}

// 3 2 4 -1 -1 5 -1 -1 1 7 -1 -1 8 -1 -1