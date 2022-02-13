class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        for(int i = 1;i<n;i++){
            int n2 = 2*dp[index2];
            int n3 = 3*dp[index3];
            int n5 = 5*dp[index5];
            dp[i] = min(min(n2,n3),n5);
            //cout<<dp[i]<<endl;
            if(dp[i] == n2)
                index2++;
            if(dp[i] == n3)
                index3++;
            if(dp[i] == n5)
                index5++;
        }
        return dp[n-1];
    }
};