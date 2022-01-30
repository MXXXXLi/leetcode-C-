class Solution {
public:
    int ret;
    int findTargetSumWays(vector<int>& nums, int target) {
        ret = 0;
        backtrack(nums,target,0,0);
        return ret;
    }
    void backtrack(vector<int>& nums,int target,int u,int sum)
    {
        if(u>nums.size())
            return;
        if(u==nums.size())
        {
            if(sum==target)
                ret++;
            return;
        }
        backtrack(nums,target,u+1,sum+nums[u]);
        backtrack(nums,target,u+1,sum-nums[u]);
    }
};