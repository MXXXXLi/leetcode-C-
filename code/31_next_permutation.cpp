class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ptr1 = n-1;
        int ptr2 = n-1;
        while(ptr1>0&&nums[ptr1-1] >= nums[ptr1])
            ptr1--;
        if(ptr1 == 0){
            sort(nums.begin(),nums.end());
            return;
        }
        else{
            ptr1-- ;
            while(nums[ptr2] <= nums[ptr1])
                ptr2--;
        }
        int temp = nums[ptr2];
        nums[ptr2] = nums[ptr1];
        nums[ptr1] = temp;
        sort(nums.begin()+ptr1+1,nums.end());
        return;
    }
};
