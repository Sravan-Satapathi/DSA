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
    int check(TreeNode* node,int targetSum,long long& preSum,unordered_map<long long,int>& mpp){
        if(node==nullptr) return 0;
        int count=0;
        preSum+=node->val;
        if(mpp.find(preSum-targetSum)!=mpp.end()) count+=mpp[preSum-targetSum];
        mpp[preSum]++;
        count+=check(node->left,targetSum,preSum,mpp);
        count+=check(node->right,targetSum,preSum,mpp);
        mpp[preSum]--;
        if(mpp[preSum]==0) mpp.erase(preSum);
        preSum-=node->val;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long preSum=0;
        unordered_map<long long,int> mpp;
        mpp[0]=1;
        return check(root,targetSum,preSum,mpp);
    }
};
