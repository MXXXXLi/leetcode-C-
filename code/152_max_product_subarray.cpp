class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = nums.size();
        //vector<int> dp(l);
        //vector<int> dpMin(l);
        int dpPre = nums[0];
        int dpMinPre = nums[0];
        int maxMul = nums[0];
        for(int i = 1;i<l;++i)
        {
            int pre = dpPre;
            dpPre = max(max(pre*nums[i],nums[i]),dpMinPre*nums[i]);
            dpMinPre = min(min(pre*nums[i],nums[i]),dpMinPre*nums[i]);
            maxMul = max(maxMul,dpPre);
        }
        return maxMul;
    }
};