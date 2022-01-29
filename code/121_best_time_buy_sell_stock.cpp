class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int pre = 0;
        int minPrice = prices[0];
        for(int p:prices){
            if(p > minPrice)
                pre = max(pre,p-minPrice);
            else
                minPrice = p;
            maxP = max(pre,maxP);
        }
        return maxP;
    }
};
