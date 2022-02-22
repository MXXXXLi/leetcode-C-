class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6,1.0/6.0);//此时dp表示只有一个骰子时，点数的概率
        for(int i = 2;i<n+1;i++)
        {
            vector<double> tmp(5*i+1,0);
            for(int a = 0; a<dp.size(); a++)//dp表示i-1个骰子时的概率数组
            {
                for(int k = 0;k<6;k++)//增加一个骰子，每个点数出现的概率为1/6,计算i各骰子时的概率数组
                {
                    tmp[a+k] += dp[a]*1.0/6.0;
                }
            }
            dp = tmp;//更新dp为i个骰子的概率数组
        }
        return dp;
    }
};