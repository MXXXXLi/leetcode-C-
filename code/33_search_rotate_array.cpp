class Solution {
public:
    int search(vector<int>& nums, int target) {
        //首先找到旋转位置的索引
        int l = 0, r = nums.size()-1;
        int index = 0;
        while(l<r){
            int mid = ceil((l+r)/2+1);
                if(nums[mid]<nums[mid-1]){
                    index = mid;
                    break;
                }
            
            if(nums[mid]>nums[nums.size()-1])
            {
                l = mid;
            }
            else
            {
                r = mid-1;
            }
        }
        //cout<<index<<endl;
        if(index == 0)
            return find(nums,0,nums.size()-1,target);
        if(target==nums[index])
            return index;
        else if(target>=nums[0])
            return find(nums,0,index-1,target);
        else
            return find(nums,index,nums.size()-1,target);
    }
    int find(vector<int>& nums, int l, int r, int target){
        //cout<<l<<r<<endl;
        if(target>nums[r]||target<nums[l])
            return -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]>target){
                r = mid-1;
            }else {
                l = mid+1;
            }
        }
        return -1;
    }
};