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

void childrenSum(TreeNode* node){
    if(node==nullptr) return;
    int child_sum=0;
    if(node->left) child_sum+=node->left->val;
    if(node->right) child_sum+=node->right->val;
    if(child_sum>=node->val) node->val=child_sum;
    else{
        if(node->left) node->left->val=node->val;
        if(node->right) node->right->val=node->val;
    }
    childrenSum(node->left);
    childrenSum(node->right);
    child_sum=0;
    if(node->left) child_sum+=node->left->val;
    if(node->right) child_sum+=node->right->val;
    if(node->left || node->right) node->val=child_sum;
}
void in_Order(TreeNode* node){
    if(node==nullptr) return;
    in_Order(node->left);
    cout<<node->val<<" ";
    in_Order(node->right);
}

int main(){
    TreeNode* root=new TreeNode(40);
    root->left=new TreeNode(10);
    root->right=new TreeNode(20);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(30);
    root->right->right=new TreeNode(40);
    in_Order(root);
    cout<<endl;
    childrenSum(root);
    in_Order(root);
    return 0;
}
