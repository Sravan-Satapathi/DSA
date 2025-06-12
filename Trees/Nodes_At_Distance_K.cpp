/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=nullptr;
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    parent[node->left]=node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right]=node;
                    q.push(node->right);
                }
            }
        }
    }
    void findNodes(TreeNode* target,int&k,unordered_map<TreeNode*,TreeNode*>& parent,
    vector<int>& result){
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        int dis=0;
        while(!q.empty()){
            int len=q.size();
            if(dis==k){
                while(!q.empty()){
                    result.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    visited[node->right]=true;
                    q.push(node->right);
                }
                if(parent[node] && !visited[parent[node]]){
                    visited[parent[node]]=true;
                    q.push(parent[node]);
                }
            }
            dis++;
        }
    }
//main call
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if(root==nullptr) return result;
        unordered_map<TreeNode*,TreeNode*> parent;
        markParent(root,parent);
        findNodes(target,k,parent,result);
        return result;
    }
};
