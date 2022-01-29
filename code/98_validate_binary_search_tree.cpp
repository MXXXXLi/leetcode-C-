class Solution {
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if(!isValidBST(root->left))
            return false;
        if(pre)
            if(root->val<=pre->val) return false;
        pre = root;
        if(!isValidBST(root->right))
            return false;
        return true;
    }
};