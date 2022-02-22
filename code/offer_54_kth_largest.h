/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    int kthLargest(TreeNode* root, int k) {
        ans = 0;
        int count = 0;
        if(root)
            help(root,k,count);
        return ans;
    }
    void help(TreeNode* root, int k, int& count){
        if(root->right)
            help(root->right,k,count);
        count++;
        if(count == k) 
        {
            ans = root->val;
            return;
        }
        if(root->left)
            help(root->left,k,count);
    }


};