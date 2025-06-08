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

void traversal(TreeNode* node,int level,vector<int>& result){
    if(node==nullptr) return;
    if(level==result.size()){
        result.push_back(node->val);
    }
    traversal(node->right,level+1,result);
    traversal(node->left,level+1,result);
}
//main call
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    traversal(root,0,result);
    return result;
}
