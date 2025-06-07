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

vector<int> bottomView(TreeNode *root) {
    vector<int> result;
    if(root==NULL) return result;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    map<int,int> mpp;
    while(!q.empty()){
        TreeNode* node=q.front().first;
        int vertical=q.front().second;
        q.pop();
        mpp[vertical]=node->val;
        if(node->left) q.push({node->left,vertical-1});
        if(node->right) q.push({node->right,vertical+1});
    }
    for(auto it:mpp){
        result.push_back(it.second);
    }
    return result;
}
