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


//PreOrder
vector<int> preOrder(TreeNode* root){
    vector<int> result;
    if(root==nullptr) return result;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node=st.top();
        st.pop();
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
        result.push_back(node->val);
    }
    return result;
}


//InOrder
vector<int> inOrder(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* node=root;
    while(true){
        if(node!=nullptr){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()) break;
            node=st.top();
            st.pop();
            result.push_back(node->val);
            node=node->right;
        }
    }
    return result;
}


//PostOrder
vector<int> postOrder(TreeNode* root){
    vector<int> result;
    if(root==nullptr) return result;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node=st.top();
        st.pop();
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
        result.push_back(node->val);
    }
    reverse(result.begin(),result.end());
    return result;
}
