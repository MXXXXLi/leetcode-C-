class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] = 1;
        int maxL = 1;
        for(int i = 1;i < n;i++)
        {
            int ll = 1;
            for(int j = 0;j<i;j++){
                
                if(nums[i]>nums[j]){
                    ll = max(ll,dp[j] + 1);
                }
            }
            dp[i] = ll;
            maxL = max(maxL,dp[i]);
        }
        return maxL;
    }
};