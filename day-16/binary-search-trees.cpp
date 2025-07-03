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
node* insert(node* root , int val){
    if(root == NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insert(root->left , val);
    }
    else{
        root->right=insert(root->right,val);
    }
}
node* buildBST(vector <int> arr){
    node* root=NULL;
    for(int val : arr){
        root=insert( root ,val);

    }
    return root;

}
bool find(node* root ,int target){
     if(root == NULL){
        return false;
    }
    if(root->data == target){
        return true;

    }
    if(root->data<target){
        find(root->left ,target);
    }
    else{
        find(root->left,target);
    }
    


}
void inorder(node* root){
     if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}
int main() {
    vector<int>arr={5,3,6,7,8,2,1,4,9};
    node* root;
   root= buildBST(arr);
   inorder(root);
   cout << endl;
   cout << find(root,22)<<endl;

    
}