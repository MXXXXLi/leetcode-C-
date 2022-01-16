class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        int pre1 = 1;
        int pre2 = 2;
        int ret;
        for(int i = 3;i<=n;i++)
        {
            ret = pre1+pre2;
            pre1 = pre2;
            pre2 = ret;
        }
        return ret;
    }
};
