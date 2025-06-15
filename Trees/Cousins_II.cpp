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

//Leetcode 2641
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        int currLevelSum=root->val;
        while(!q.empty()){
            int len=q.size();
            int nextLevelSum=0;
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                node->val=currLevelSum-node->val;
                int sibSum=0;
                if(node->left) sibSum+=node->left->val;
                if(node->right) sibSum+=node->right->val;
                if(node->left){
                    nextLevelSum+=node->left->val;
                    node->left->val=sibSum;
                    q.push(node->left);
                } 
                if(node->right){
                    nextLevelSum+=node->right->val;
                    node->right->val=sibSum;
                    q.push(node->right);
                }
            }
            currLevelSum=nextLevelSum;
        }
        return root;
    }
};
