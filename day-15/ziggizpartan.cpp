#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node definition
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};

// Build binary tree recursively from user input
TreeNode* buildTree() {
    int data;
    cin >> data;
    if (data == -1) return nullptr;

    TreeNode* root = new TreeNode(data);
    cout << "Enter left of " << data << ": ";
    root->left = buildTree();
    cout << "Enter right of " << data << ": ";
    root->right = buildTree();

    return root;
}

// ZigZag level order traversal
void zigZagTraversal(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();

            // Place node value in correct index
            int index = leftToRight ? i : size - i - 1;
            level[index] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // Print current level
        for (int val : level) cout << val << " ";
        cout << endl;

        leftToRight = !leftToRight;
    }
}

// Main function
int main() {
    cout << "Enter tree data (use -1 for NULL):" << endl;
    TreeNode* root = buildTree();

    cout << "\nZigZag Level Order Traversal:\n";
    zigZagTraversal(root);

    return 0;
}

//1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1