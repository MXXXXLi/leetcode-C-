class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int maxSpan = 0;
        bool isOne = false;
        for(int i = 0;i<m;++i)
            if(matrix[i][0] == '1'){
                isOne = true;
                maxSpan = 1;
                break;
            }
        if(isOne)
            for(int i = 0;i<m;++i)
                dp[i][0] = 1;
        bool isOne1 = false;
        for(int i = 0;i<n;++i)
            if(matrix[0][i] == '1'){
                isOne1 = true;
                maxSpan = 1;
                break;
            }
        if(isOne1)
            for(int i = 0;i<n;++i)
                dp[0][i] = 1;
        for(int i = 1;i < m;++i)
            for(int j = 1;j < n;++j)
            {
                if(matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                {
                    int properSpan = min(dp[i-1][j],dp[i][j-1])+1;
                    if(matrix[i-properSpan+1][j-properSpan+1] == '1'&&matrix[i][j-properSpan+1] == '1'&&matrix[i-properSpan+1][j]=='1'){
                        dp[i][j] = properSpan;
                        maxSpan = max(maxSpan,dp[i][j]);
                    }
                    else
                        dp[i][j] = properSpan-1;
                }
            }
            return maxSpan*maxSpan;

                
    }
};