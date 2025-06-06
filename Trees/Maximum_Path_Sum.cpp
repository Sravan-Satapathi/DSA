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


int sum(TreeNode* node,int& result){
    if(node==nullptr) return 0;
    int lh=max(0,sum(node->left,result));
    int rh=max(0,sum(node->right,result));
    result=max(result,lh+rh+node->val);
    return node->val+max(lh,rh);
}
//main call
int maxPathSum(TreeNode* root) {
    if(root==nullptr) return 0;
    int result=INT_MIN;
    sum(root,result);
    return result;
}
