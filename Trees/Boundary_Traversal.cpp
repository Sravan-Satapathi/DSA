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


bool isLeaf(Node* node){
    return !node->left && !node->right;
}
void addLeaves(Node* node,vector<int>& result){
    if(isLeaf(node)){
        result.push_back(node->val);
        return;
    }
    if(node->left) addLeaves(node->left,result);
    if(node->right) addLeaves(node->right,result);
}
void addLeftBoundary(Node* node,vector<int>& result){
    if(!node || isLeaf(node)) return;
    result.push_back(node->val);
    if(node->left) addLeftBoundary(node->left,result);
    else addLeftBoundary(node->right,result);
}
void addRightBoundary(Node* node,vector<int>& result){
    if(!node || isLeaf(node)) return;
    if(node->right) addRightBoundary(node->right,result);
    else addRightBoundary(node->left,result);
    result.push_back(node->val);
}
//main call
vector<int> boundaryTraversal(Node *root) {
    vector<int> result;
    if(root==NULL) return result;
    if(!isLeaf(root)) result.push_back(root->val);
    addLeftBoundary(root->left,result);
    addLeaves(root,result);
    addRightBoundary(root->right,result);
    return result;
}
