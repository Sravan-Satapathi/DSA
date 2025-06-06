#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Preorder
void preOrder(TreeNode* node){
    if(node==nullptr) return;
    cout<<node->val<<" ";
    preOrder(node->left);
    preOrder(node->right);
}


//Inorder
void inOrder(TreeNode* node){
    if(node==nullptr) return;
    inOrder(node->left);
    cout<<node->val<<" ";
    inOrder(node->right);
}


//PostOrder
void postOrder(TreeNode* node){
    if(node==nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->val<<" ";
}
