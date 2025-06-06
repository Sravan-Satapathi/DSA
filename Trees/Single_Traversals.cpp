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

void traversal(TreeNode* node){
    stack<pair<TreeNode*,int>> st;
    vector<int> preOrder,postOrder,inOrder;
    st.push({node,1});
    while(!st.empty()){
        TreeNode* node=st.top().first;
        int count=st.top().second;
        st.pop();
        if(count==1){
            preOrder.push_back(node->val);
            st.push({node,2});
            if(node->left) st.push({node->left,1});
        }
        else if(count==2){
            inOrder.push_back(node->val);
            st.push({node,3});
            if(node->right) st.push({node->right,1});
        }
        else{
            postOrder.push_back(node->val);
        }
    }
}
