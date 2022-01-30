class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        int ret = 0;
        for(int i = 0;i<n;++i){
            dp[i][i] = true;
            ret++;
        }
        for(int i = 1;i<n;++i)
        {
            for(int j = i-1;j >=0;--j)
            {
                if(s[i] == s[j]){
                    if(j+1<=i-1){
                        dp[j][i] = dp[j+1][i-1];
                        if(dp[j][i])
                            ret ++;
                    }
                    else{
                        dp[j][i] = true;
                        ret ++;
                    }
                }
                else
                    dp[j][i] = false;
            }
        }
        return ret;
    }
};