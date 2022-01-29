class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        double ans = 1;
        long nAbso = n;
        nAbso = nAbso>0?nAbso:-nAbso;
        bool flag = n>0?true:false;
        unsigned int countSum = 0;
        while(countSum < nAbso){
            double pow = x;
            unsigned int count = 1;
            unsigned int nLeft = nAbso - countSum;
            while(count+count < nLeft){
                count = count+count;
                pow = pow*pow;
            }
            countSum += count;
            ans *= pow;
        }
        return flag == true?ans:1/ans;
    }
};
