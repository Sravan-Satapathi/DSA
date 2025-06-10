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


TreeNode* helper(TreeNode* node){
    if(node->left==nullptr) return node->right;
    if(node->right==nullptr) return node->left;
    TreeNode* rightChild=node->right;
    TreeNode* rightmost=node->left;
    while(rightmost->right!=nullptr){
        rightmost=rightmost->right;
    }
    rightmost->right=rightChild;
    return node->left;
}
//main call
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==nullptr) return root;
    if(root->val==key){
        return helper(root);
    }
    TreeNode* node=root;
    while(node!=nullptr){
        if(key<node->val){
            if(node->left!=nullptr && node->left->val==key){
                node->left=helper(node->left);
                break;
            }
            else node=node->left;
        }
        else{
            if(node->right!=nullptr && node->right->val==key){
                node->right=helper(node->right);
                break;
            }
            else node=node->right;
        }
    }
    return root;
}
