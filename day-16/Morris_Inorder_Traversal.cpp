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
void morristraversal(node *root, vector<int> &ans)
{

    node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            node *ip = curr->left;
            while (ip->right != NULL && ip->right != curr)
            {
                ip = ip->right;
            }
            if (ip->right == NULL)
            {
                ip->right = curr;
                curr = curr->left;
            }
            else
            {
                ip->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    vector<int> ans;
    morristraversal(root, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    // 3 2 4 -1 -1 5 -1 -1 1 7 -1 -1 8 -1 -1
}