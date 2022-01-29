class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(3,-1000000));
//0:进行完本次操作后持有(本次买，或者之前买过这次也没卖，
//1:进行完本次操作后冷冻(卖)，
//2：进行完本次操作后非冷冻，不持有(不买，不卖)
        dp[0][0] = 0-prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for(int i = 1;i<n;++i)
        {
            dp[i][0] = max(dp[i-1][2]-prices[i],dp[i-1][0]);
            dp[i][1] = dp[i-1][0]+prices[i];
            dp[i][2] = max(dp[i-1][1],dp[i-1][2]);
        }
        return max(dp[n-1][1],dp[n-1][2]);
    }
};