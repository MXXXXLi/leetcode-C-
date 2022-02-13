class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        vector<int> temp(n);
        return mergeSort(nums,0,r,temp);
    }
    int mergeSort(vector<int>& nums, int l, int r,vector<int>& temp){
        if(l>=r)
            return 0;//终止条件
        int mid = (l+r)/2;
        int res =  mergeSort(nums, l, mid, temp) + mergeSort(nums, mid+1, r, temp);//递归，划分
        //temp用来存储排序前的状态，
        for(int index = l; index <= r; index++){
            temp[index] = nums[index];
        }
        int indexl = l,indexr = mid+1;
        //归并
        for(int k = l; k<= r; k++){
            if(indexl == mid+1)
                nums[k] = temp[indexr++];
            else if(indexr == r+1)
                nums[k] = temp[indexl++];
            else{
                if(temp[indexl]<=temp[indexr]){
                nums[k] = temp[indexl++];    
                }
                else{
                    nums[k] = temp[indexr++];
                    res+=mid-indexl+1;
                }     
            }
        }
        return res;
    }


};