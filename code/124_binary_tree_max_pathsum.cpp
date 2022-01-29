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
    int max1;
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        max1 = root->val;
        dfs(root);
        return max1;

    }
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int leftMax = max(dfs(root->left),0);
        int rightMax = max(dfs(root->right),0);
        max1 = max(max1,leftMax+rightMax+root->val);
        return max(root->val+leftMax,root->val+rightMax);
    }

};