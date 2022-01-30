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
    int maxDiameter;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        help(root);
        return maxDiameter;
    }
    int help(TreeNode* root)
    {
        if(!root) return 0;
        if(!root->left&&!root->right) return 0;
        int left = help(root->left);
        int right = help(root->right);
        int ret = max(left,right);
        if(!root->left||!root->right) 
            maxDiameter = max(maxDiameter,left+right+1);
        else
            maxDiameter = max(maxDiameter,left+right+2);
        return ret+1;
    }
};