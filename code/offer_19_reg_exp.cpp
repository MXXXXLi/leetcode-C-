class Solution {
public:
    bool match(char p,char s)
    {
        if(p == s ||p == '.')
            return true;
        else
            return false;
    }
    bool isMatch(string s, string p) {
        int pSize = p.size();
        int sSize = s.size();
        vector<vector<bool>>dp(pSize+1,vector<bool>(sSize+1,false));
        dp[0][0] = true;
        for(int i = 1;i <= pSize;i++)
        {
            if(p[i-1] == '*')
                dp[i][0] = dp[i-2][0];
        }
        for(int i = 1;i <= pSize;i++)
        {
            for(int j = 1;j <= sSize;j++)
            {
                if(p[i-1] != '*')
                    dp[i][j] = dp[i-1][j-1]&&match(p[i-1],s[j-1]);
                else if(p[i-1] == '*')
                {
                    if(match(p[i-2],s[j-1])){
                        dp[i][j] = dp[i][j-1]||dp[i-2][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i-2][j];
                    }

                }
            }
        }
        return dp[pSize][sSize];
    }
};
