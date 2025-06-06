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

int depth(TreeNode* node){
    if(node==nullptr) return 0;
    int lh=depth(node->left);
    int rh=depth(node->right);
    if(lh==-1 || rh==-1 || abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
}
//main call
bool isBalanced(TreeNode* root) {
    int len=depth(root);
    if(len==-1) return false;
    return true;
}
