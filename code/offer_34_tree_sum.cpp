class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root) return vector<vector<int>>();
        int temp = root->val;
        vector<int> road;
        road.push_back(root->val);
        backtrack(root,target,temp,road);
        return ans;
    }
    void backtrack(TreeNode* root, int target, int temp,vector<int>& road)
    {
        if(!root->left&&!root->right)
        {
            if(temp == target)
                ans.push_back(road);
            return;
        }
        if(root->left) 
        {
            road.push_back(root->left->val);
            backtrack(root->left,target,temp+root->left->val,road);
            road.erase(road.end()-1);
        }
        if(root->right) 
        {
            road.push_back(root->right->val);
            backtrack(root->right,target,temp+root->right->val,road);
            temp-=root->right->val;
            road.erase(road.end()-1);
        }
    }
};