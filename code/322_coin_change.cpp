class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        dp[0] = 0;
        for(auto i: coins)
        {
            if(i<amount+1)
                dp[i] = 1;
        }
        for(int i = 1;i < amount+1;++i)
        {
            if(dp[i]!=-1)
                continue;
            for(auto j:coins)
            {
                if(j > i)
                    continue;
                //cout<<"dp["<<i<<"-"<<j<<"] "<<dp[i-j]<<endl;
                if(dp[i-j]!=-1)
                    dp[i] = (dp[i] == -1)?(dp[i - j] + 1):min(dp[i],dp[i-j] +1);
                else
                    continue;
            }
        }
        return dp[amount];
    }
};