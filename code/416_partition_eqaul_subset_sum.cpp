    bool canPartition(vector<int>& nums) {
        //动态规划，转化为01背包问题
        int sum = 0;
        for(auto & n:nums){
            sum += n;
        }
        if(sum%2 != 0)
            return false;
        int target = sum/2;
        vector<vector<bool>>dp(nums.size()+1,vector<bool>(target+1,false));
        for(int i = 0;i<nums.size()+1;i++){
            dp[i][0] = true;
        }
        dp[0][0] = true;
        
        for(int t = 0;t<=target;t++){
            for(int i = 1;i<=nums.size();i++){
                dp[i][t] = dp[i-1][t]||(t-nums[i-1]>=0?dp[i-1][t-nums[i-1]]:false);
            }
        }
        return dp[nums.size()][target];
    }