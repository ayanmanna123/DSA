#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildtree(node *root)
{
    cout << "enter the data ;" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter data for left" << data << endl;
    root->left = buildtree(root->left);
    cout << "enter data for right " << data << endl;
    root->right = buildtree(root->right);
    return root;
}
void inlineorder(node* root){
    if(root == NULL){
        return ;
    }
     inlineorder(root->left);
    cout << root->data<< " ";
    inlineorder(root->right);

}
void preorder(node* root){
    if(root==NULL){
        return;

    }
    cout <<root->data <<" ";
    preorder(root->left);
    preorder(root->right);

}
void postordet(node* root){
    if(root == NULL){
        return;

    }
    postordet(root->left);
    postordet(root->right);
    cout << root->data<<" ";
}
void lavelOrderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int count=0;
    while (!q.empty())
    {
        node *temp = q.front();
       
        q.pop();

        if (temp == NULL)
        {   count++;
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {   cout << temp->data << " ";
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
     cout<<count<<endl;
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    lavelOrderTraversal(root);
   
    // cout << " this is inlineorder "<<endl;
    // inlineorder(root);
    // cout << "this is preorder"<<endl;
    // preorder(root);
    // cout << "this is post order "<<endl;
    // postordet(root);

    // 3 2 4 -1 -1 5 -1 -1 1 7 -1 -1 8 -1 -1
}