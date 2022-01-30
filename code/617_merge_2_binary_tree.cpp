class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        root1->val += root2->val;
        TreeNode* left = mergeTrees(root1->left,root2->left);
        TreeNode* right = mergeTrees(root1->right,root2->right);
        root1->left = left;
        root1->right = right;
        return root1;
    }
};