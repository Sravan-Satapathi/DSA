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

int widthOfBinaryTree(TreeNode* root) {
    if(root==nullptr) return 0;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    int width=0;
    while(!q.empty()){
        int len=q.size();
        int min_ind=q.front().second;
        int first,last;
        for(int i=0;i<len;i++){
            TreeNode* node=q.front().first;
            long long ind=q.front().second-min_ind;
            q.pop();
            if(i==0) first=ind;
            if(i==len-1) last=ind;
            if(node->left) q.push({node->left,2*ind+1});
            if(node->right) q.push({node->right,2*ind+2});
        }
        width=max(width,last-first+1);
    }
    return width;
}
