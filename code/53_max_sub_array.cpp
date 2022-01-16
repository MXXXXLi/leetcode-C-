class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int pre = nums[0];
        int maxSum = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            pre = max(pre+nums[i],nums[i]);
            maxSum = max(maxSum,pre);
        }
        return maxSum;
    }

};
