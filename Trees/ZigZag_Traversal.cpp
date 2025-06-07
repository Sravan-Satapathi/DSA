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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root==nullptr) return result;
    queue<TreeNode*> q;
    q.push(root);
    bool zigzag=false;
    while(!q.empty()){
        int len=q.size();
        vector<int> level(len);
        for(int i=0;i<len;i++){
            TreeNode* node=q.front();
            q.pop();
            if(!zigzag)  level[i]=node->val;
            else level[len-1-i]=node->val;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        zigzag=!zigzag;
        result.push_back(level);
    }
    return result;
}
