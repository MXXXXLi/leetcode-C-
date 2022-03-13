class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        vector<int> val(n+2);
        val[0] = 1;
        val[n+1] = 1;
        for(int i = 0;i<n;i++){
            val[i+1] = nums[i];
        }
        for(int i = n-1;i>=0;i--){
            for(int j = i+2;j<n+2;j++){
                for(int k = i+1;k<j;k++){
                    int sum = val[k]*val[i]*val[j];
                    sum += dp[i][k]+dp[k][j];
                    dp[i][j] = max(dp[i][j],sum);
                }
            }
        }
        return dp[0][n+1];
    }
};