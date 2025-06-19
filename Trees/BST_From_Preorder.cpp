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
    TreeNode* construct(int& ind,vector<int>& preorder,int maxi){
        if(ind==preorder.size() || preorder[ind]>maxi) return nullptr;
        TreeNode* root=new TreeNode(preorder[ind]);
        ind++;
        root->left=construct(ind,preorder,root->val);
        root->right=construct(ind,preorder,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        return construct(ind,preorder,INT_MAX);
    }
};
