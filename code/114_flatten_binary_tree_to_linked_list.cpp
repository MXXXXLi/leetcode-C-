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
    bool isBalancedHight(TreeNode* root,int& hight)
    {
        if(!root) return true;
        int hightLeft = 0, hightRight = 0;
        bool isBLeft = isBalancedHight(root->left,hightLeft);
        bool isBRight = isBalancedHight(root->right,hightRight);
        hight = max(hightRight,hightLeft)+1;
        return isBLeft&&isBRight&&(abs(hightLeft-hightRight)<=1);
    }
    bool isBalanced(TreeNode* root) {
        int hight = 0;
        return isBalancedHight(root,hight);
    }
};