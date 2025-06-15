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

//Leetcode 2471
class Solution {
public:
    int calcSwaps(vector<int>& level,int n){
        vector<int> sortedLevel(level.begin(),level.end());
        sort(sortedLevel.begin(),sortedLevel.end());
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[level[i]]=i;
        }
        int count=0;
        for(int i=0;i<n;i++){
            int ind=mpp[sortedLevel[i]];
            if(i!=ind){
                mpp[sortedLevel[i]]=i;
                mpp[level[i]]=ind;
                swap(level[i],level[ind]);
                count++;
            }
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count=0;
        while(!q.empty()){
            int len=q.size();
            vector<int> level;
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            count+=calcSwaps(level,len);
        }
        return count;
    }
};
