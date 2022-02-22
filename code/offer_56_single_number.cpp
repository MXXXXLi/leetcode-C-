class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int loop = nums.size()/3;
        for(int i = 0;i<loop;i++){
            if(nums[i*3] != nums[i*3+2]){
                return nums[i*3];
            }
        }
        return nums[nums.size() - 1];
    }
};