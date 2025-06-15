//From Preorder and Inorder
class Solution {
public:
    TreeNode* construct(int preStart,int preEnd,vector<int>& preorder, 
    int inStart,int inEnd,vector<int>& inorder,unordered_map<int,int>& inMap){
        if(preStart>preEnd || inStart>inEnd) return nullptr;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=inMap[root->val];
        int nLeft=inRoot-inStart;
        root->left=construct(preStart+1,preStart+nLeft,preorder,inStart,inRoot-1,inorder,inMap);
        root->right=construct(preStart+nLeft+1,preEnd,preorder,inRoot+1,inEnd,inorder,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len=inorder.size();
        unordered_map<int,int> inMap;
        for(int i=0;i<len;i++){
            inMap[inorder[i]]=i;
        }
        TreeNode* root=construct(0,len-1,preorder,0,len-1,inorder,inMap);
        return root;
    }
};


//From Postorder and Inorder
class Solution {
public:
    TreeNode* construct(int inStart,int inEnd,vector<int>& inorder,
    int postStart,int postEnd,vector<int>& postorder,unordered_map<int,int>& inMap){
        if(inStart>inEnd || postStart>postEnd) return nullptr;
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int inRoot=inMap[root->val];
        int nLeft=inRoot-inStart;
        root->left=construct(inStart,inRoot-1,inorder,postStart,postStart+nLeft-1,postorder,inMap);
        root->right=construct(inRoot+1,inEnd,inorder,postStart+nLeft,postEnd-1,postorder,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len=inorder.size();
        unordered_map<int,int> inMap;
        for(int i=0;i<len;i++){
            inMap[inorder[i]]=i;
        }
        return construct(0,len-1,inorder,0,len-1,postorder,inMap);
    }
};
