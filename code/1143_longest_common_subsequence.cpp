class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1,vector<int>(len2,0));
        bool isFlag = false;
        for(int i = 0;i < len1;++i)
        {
            if(text1[i] == text2[0])
            {
                isFlag = true;
            }
            if(isFlag)
                dp[i][0] = 1;
        }
        isFlag = false;
        for(int i = 0;i < len2;++i)
        {
            if(text1[0] == text2[i])
            {
                isFlag = true;
            }
            if(isFlag)
                dp[0][i] = 1;
        }
        for(int i = 1;i < len1;++i)
        {
            for(int j = 1;j < len2;++j)
            {
                if(text1[i] == text2[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                //cout<<dp[i][j]<<endl;
            }
        }
        return dp[len1-1][len2-1];
    }
};