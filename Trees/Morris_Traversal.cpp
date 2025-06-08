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

//InOrder Traversal
vector<int> inOrder(TreeNode* root){
    vector<int> result;
    TreeNode* curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            result.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==nullptr){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=nullptr;
                result.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return result;
}

//PreOrder Traversal
vector<int> preOrder(TreeNode* root){
    vector<int> result;
    TreeNode* curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            result.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==nullptr){
                prev->right=curr;
                result.push_back(curr->val);
                curr=curr->left;
            }
            else{
                prev->right=nullptr;
                curr=curr->right;
            }
        }
    }
    return result;
}
