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

void search(TreeNode* node,int& count,int k,int& num){
    if(node==nullptr) return;
    search(node->left,count,k,num);
    count++;
    if(count==k) num=node->val;
    search(node->right,count,k,num);
}
//main call
int kthSmallest(TreeNode* root, int k) {
    int count=0,num=0;
    search(root,count,k,num);
    return num;
}
