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
void topview(node *root)
{
    queue<pair<node *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (q.size() > 0)
    {
        node *curr = q.front().first;
        int currhd = q.front().second;
        q.pop();
        
        
            m[currhd] = curr->data;
        
        if(curr->left != NULL){
            q.push({curr->left,currhd-1});

        }
         if(curr->right != NULL){
            q.push({curr->right,currhd+1});

        }
    }
    for(auto it : m){
        cout<< it.second <<" ";

    }
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    topview(root);
    // 3 2 4 -1 -1 5 -1 -1 1 7 -1 -1 8 -1 -1
}