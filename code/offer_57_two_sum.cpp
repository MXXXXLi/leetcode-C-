class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> ans;
        while(left<right){
            if(nums[left] + nums[right]>target)
                right--;
            else if(nums[left] + nums[right]<target)
                left++;
            else{
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
                return ans;
            }

        }
        return ans;
    }
};