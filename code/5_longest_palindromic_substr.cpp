class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int maxSpan = 1;
        int start = 0;
        for(int i = 0;i<s.size();i++){
            dp[i][i] = true;
            if(i<s.size()-1)
            {
                if(s[i]==s[i+1]){
                    dp[i][i+1] = true;
                    maxSpan = 2;
                    start = i;
                }
            }
        }
        for(int l = 2;l < s.size();l++){
            for(int i = 0;i<l;i++)
            {
                if(dp[i][l])break;
                dp[i][l] = dp[i+1][l-1]&&(s[i]==s[l])?true:false;
                if(dp[i][l])
                {
                    if(l-i+1>maxSpan){
                        maxSpan = l-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxSpan);

    }
};
