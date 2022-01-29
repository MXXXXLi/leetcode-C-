class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0],nums[1]);
        vector<int>dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i = 2;i<nums.size();++i)
        {
            if(i-3>-1)
                dp[i] = max(max(dp[i-1],dp[i-2] + nums[i]),dp[i-3]+nums[i]);
            else
                dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};