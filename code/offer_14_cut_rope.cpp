class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3;i<(n+1);i++)
        {
            for(int j = 2;j<i;++j)
            {
                dp[i] = max(dp[i],max(j*dp[i-j],j*(i-j)));
            }
        }
        return dp[n];
    }
};
