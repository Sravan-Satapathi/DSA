struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int depth(TreeNode* node){
    if(node==nullptr) return 0;
    int lh=depth(node->left);
    int rh=depth(node->right);
    return 1+max(lh,rh);
}
