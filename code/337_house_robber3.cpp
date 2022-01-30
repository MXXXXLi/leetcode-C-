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
    map<TreeNode*,int> memo;
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(memo.find(root)!= memo.end()) return memo[root];
        int left = 0,right = 0;
        if(root->left) left = rob(root->left->left) + rob(root->left->right);
        if(root->right) right = rob(root->right->left) + rob(root->right->right);
        int rootMax = root->val+left+right;

        int left2 = rob(root->left);
        int right2 = rob(root->right);

        int max2 = left2+right2;

        int ret = max(rootMax,max2);
        memo.insert(make_pair(root,ret));
        return ret;
    }
};