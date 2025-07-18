#include <bits/stdc++.h>
using namespace std;
class node
{
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

void lavelOrderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    cout << root->data <<"|";
    q.push(NULL);
    
    int count=1;
    stack <int > ans;
    while (!q.empty())
    {
        node *temp = q.front();
       
        q.pop();

        if (temp == NULL)
        {
            
             while(ans.size()!=0){
                 cout << ans.top() << " ";
                 ans.pop();
                
            }
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {  //  cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
                ans.push(temp->left->data);
            }
            if (temp->right)
            {
                q.push(temp->right);
                ans.push(temp->right->data);
            }
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    lavelOrderTraversal(root);
    cout << " this is inlineorder "<<endl;
    
     

    // 3 2 4 -1 -1 5 -1 -1 1 7 -1 -1 8 -1 -1
}
    
