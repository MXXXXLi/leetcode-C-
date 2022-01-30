class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return pathSum(root->left,targetSum)+pathSum(root->right,targetSum)+help(root,targetSum);
    }
    int help(TreeNode* root, int target){
        if(!root) return 0;
        int ret = 0;
        if(root->val == target)ret+=1;
        return ret+help(root->left,target-root->val)+help(root->right,target-root->val);
    }
};