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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL || root==p || root==q){
        return root;
    }
    TreeNode* left_node=lowestCommonAncestor(root->left,p,q);
    TreeNode* right_node=lowestCommonAncestor(root->right,p,q);
    if(left_node==NULL) return right_node;
    else if(right_node==NULL) return left_node;
    else return root;
}
