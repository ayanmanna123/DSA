#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree() {
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    node* root = new node(data);
    cout << "Enter data for left of " << data << endl;
    root->left = buildtree();
    cout << "Enter data for right of " << data << endl;
    root->right = buildtree();

    return root;
}

vector<int> leftView(node* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            node* temp = q.front();
            q.pop();

            if (i == 0) {
                ans.push_back(temp->data); // 👈 First node at this level
            }

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    return ans;
}

int main() {
    node* root = buildtree();

    vector<int> ans = leftView(root);

    cout << "\nLeft View: ";
    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}
