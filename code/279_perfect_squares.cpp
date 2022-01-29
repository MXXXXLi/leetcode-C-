class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        int a = 1;
        for(int i = 1;i<n+1;i++)
        {
            if(i == a*a){
                dp[i] = 1;
                if(i<n)
                    dp[i+1] =2;
                a++;
            }
        }
        if(dp[n]>0)return dp[n];
        for(int i = 1; i<n+1;i++)
        {
            int minDp = 10000;
            if(dp[i] >= 1 )
                continue;
            for(int j = 1;j*j<i;j++){

                minDp = min(minDp,dp[i-j*j]);
            }
            dp[i] = minDp+1;
        }
        return dp[n];
    }
};
