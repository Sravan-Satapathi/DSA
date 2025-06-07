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

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> result;
    if(root==nullptr) return result;
    queue<pair<TreeNode*,pair<int,int>>> q;
    q.push({root,{0,0}});
    map<int,map<int,multiset<int>>> mpp;
    while(!q.empty()){
        TreeNode* node=q.front().first;
        int level=q.front().second.first;
        int vertical=q.front().second.second;
        q.pop();
        mpp[vertical][level].insert(node->val);
        if(node->left) q.push({node->left,{level+1,vertical-1}});
        if(node->right) q.push({node->right,{level+1,vertical+1}});
    }
    for(auto p:mpp){
        vector<int> col;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        result.push_back(col);
    }
    return result;
}
