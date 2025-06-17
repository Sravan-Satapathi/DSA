//Bit Magic

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
    void func(TreeNode* root,int& num,int& count){
        if(root==nullptr) return;
        int curr=root->val;
        num=num^(1<<curr);
        if(isLeaf(root)){
            if((num & (num-1))==0) count++;
        }
        func(root->left,num,count);
        func(root->right,num,count);
        num=num^(1<<curr);
    }
    //main call
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==nullptr) return 0;
        int count=0,num=0;
        func(root,num,count);
        return count;
    }
};
