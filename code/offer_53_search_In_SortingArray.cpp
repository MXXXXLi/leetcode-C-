class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;
        int count = 0;
        while(left<right){
            int mid = (left + right)/2;
            if(nums[mid]>=target)
                right = mid;
            else
                left = mid+1;
        }
        while(left<nums.size()&&nums[left++] == target)
            count++;
        return count;
    }
};