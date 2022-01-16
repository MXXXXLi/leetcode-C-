class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool>dp(nums.size(),false);
        dp[0] = true;
        for(int i = 1;i<nums.size();i++)
        {
            for(int j = i-1;j>-1;j--){
                if(dp[j]&&(i-j)<=nums[j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[nums.size() -1];
    }
};
