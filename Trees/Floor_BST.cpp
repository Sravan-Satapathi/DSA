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

int floor(TreeNode* root,int val){
    int num=-1;
    while(root!=nullptr){
        if(root->val==val) return val;
        if(val<root->val) root=root->left;
        else{
            num=root->val;
            root=root->right;
        }
    }
    return num;
}
