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
    bool isSymmetric1(TreeNode* rootLeft, TreeNode* rootRight)
    {
        if(rootLeft == rootRight) return true;
        if(!rootLeft || !rootRight) return false;
        return (rootLeft->val == rootRight->val)&&isSymmetric1(rootLeft->left,rootRight->right)
        &&isSymmetric1(rootLeft->right,rootRight->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) 
            return true;
        else
            return isSymmetric1(root->left,root->right);
    }
};