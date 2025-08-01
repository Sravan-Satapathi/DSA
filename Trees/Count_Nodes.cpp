//Time Complexity - O((logn)^2)
//Space Complexity - O(logn)

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
    int rightHeight(TreeNode* node){
        int count=0;
        while(node){
            count++;
            node=node->right;
        }
        return count;
    }
    int leftHeight(TreeNode* node){
        int count=0;
        while(node){
            count++;
            node=node->left;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
