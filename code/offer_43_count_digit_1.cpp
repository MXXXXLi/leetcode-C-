class Solution {
    vector<int> a;
    int cnt;
    vector<vector<int>> dp;
public:
    int countDigitOne(int n) {
        a = vector<int>(10);
        while (n != 0) {
            a[cnt++] = n % 10;
            n /= 10;
        }
        dp = vector<vector<int>>(cnt,vector<int>(10));
        return dfs(cnt - 1, 0, true, true);
    }

    int dfs(int pos, int sum, bool lead, bool limit) {
        if (pos == -1) {
            return sum;
        }
        if (!lead && !limit && dp[pos][sum] != 0) {
            return dp[pos][sum];
        }
        int up = limit ? a[pos] : 9;
        int ans = 0;
        for (int i = 0; i <= up; i++) {
            int temp = dfs(pos - 1, sum + (i == 1 ? 1 : 0), lead && i == 0, limit && i == up);
            ans += temp;
        }
        if (!lead && !limit) {
            dp[pos][sum] = ans;
        }
        return ans;
    }
};